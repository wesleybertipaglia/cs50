import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user_id = session["user_id"]
    
    rows = db.execute("SELECT symbol, SUM(shares) as shares FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)
    
    holdings = []
    total_value = 0
    
    for row in rows:
        quote = lookup(row["symbol"])
        total = row["shares"] * quote["price"]
        holdings.append({
            "symbol": row["symbol"],
            "shares": row["shares"],
            "price": usd(quote["price"]),
            "total": usd(total)
        })
        total_value += total
    
    cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
    grand_total = total_value + cash
    
    return render_template("index.html", holdings=holdings, cash=usd(cash), grand_total=usd(grand_total))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        
        if not symbol or not shares:
            return apology("must provide stock symbol and number of shares", 400)
        
        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError()
        except ValueError:
            return apology("shares must be a positive integer", 400)
        
        quote = lookup(symbol)
        if not quote:
            return apology("invalid stock symbol", 400)
        
        price = quote["price"]
        total_cost = price * shares
        
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        
        if total_cost > user_cash:
            return apology("cannot afford", 400)
        
        db.execute("UPDATE users SET cash = cash - ? WHERE id = ?", total_cost, user_id)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", user_id, symbol, shares, price)
        
        return redirect("/")
    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions = db.execute("SELECT symbol, shares, price, created_at FROM transactions WHERE user_id = ?", user_id)
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get("username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("must provide stock symbol", 400)
        
        quote = lookup(symbol)
        if not quote:
            return apology("invalid stock symbol", 400)
        
        return render_template("quoted.html", symbol=quote["symbol"], price=usd(quote["price"]))
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username or not password or not confirmation:
            return apology("must provide username and passwords", 400)

        if password != confirmation:
            return apology("passwords do not match", 400)

        hash = generate_password_hash(password)

        try:
            db.execute("INSERT INTO users (username, hash) VALUES (?, ?)", username, hash)
        except ValueError:
            return apology("username already exists", 400)

        return redirect("/login")
    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        
        if not symbol or not shares:
            return apology("must provide stock symbol and number of shares", 400)
        
        try:
            shares = int(shares)
            if shares <= 0:
                raise ValueError()
        except ValueError:
            return apology("shares must be a positive integer", 400)
        
        user_id = session["user_id"]
        stock_shares = db.execute("SELECT SUM(shares) as shares FROM transactions WHERE user_id = ? AND symbol = ? GROUP BY symbol", user_id, symbol)[0]["shares"]
        
        if shares > stock_shares:
            return apology("too many shares", 400)
        
        quote = lookup(symbol)
        price = quote["price"]
        total_revenue = price * shares
        
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", total_revenue, user_id)
        db.execute("INSERT INTO transactions (user_id, symbol, shares, price) VALUES (?, ?, ?, ?)", user_id, symbol, -shares, price)
        
        return redirect("/")
    else:
        user_id = session["user_id"]
        stocks = db.execute("SELECT symbol FROM transactions WHERE user_id = ? GROUP BY symbol HAVING SUM(shares) > 0", user_id)
        return render_template("sell.html", stocks=stocks)

@app.route("/cash", methods=["GET", "POST"])
@login_required
def cash():    
    """Add cash to account"""
    if request.method == "POST":
        cash = request.form.get("cash")
        if not cash:
            return apology("must provide amount of cash", 400)
        
        try:
            cash = float(cash)
            if cash <= 0:
                raise ValueError()
        except ValueError:
            return apology("cash must be a positive number", 400)
        
        user_id = session["user_id"]
        db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", cash, user_id)
        return redirect("/")
    else:
        return render_template("cash.html")


@app.route("/account", methods=["GET"])
@login_required
def account():
    """Account settings"""
    user_data = db.execute("SELECT id, username, cash FROM users WHERE id = ?", session["user_id"])
    if not user_data:
        return apology("User not found", 404)

    user = user_data[0]
    user["cash"] = usd(user["cash"])

    return render_template("account.html", user=user)


@app.route("/password", methods=["GET", "POST"])
@login_required
def password():
    """Change password"""
    if request.method == "POST":
        old_password = request.form.get("old_password")
        new_password = request.form.get("new_password")
        confirmation = request.form.get("confirmation")
        
        if not old_password or not new_password or not confirmation:
            return apology("must provide old password and new password", 400)
        
        if new_password != confirmation:
            return apology("new passwords do not match", 400)
        
        user = db.execute("SELECT hash FROM users WHERE id = ?", session["user_id"])[0]
        if not check_password_hash(user["hash"], old_password):
            return apology("invalid old password", 400)
        
        hash = generate_password_hash(new_password)
        db.execute("UPDATE users SET hash = ? WHERE id = ?", hash, session["user_id"])
        
        return redirect("/account")
    else:
        return render_template("password.html")


@app.route("/delete", methods=["GET", "POST"])
@login_required
def delete():
    """Delete account"""
    if request.method == "POST":
        db.execute("DELETE FROM users WHERE id = ?", session["user_id"])
        db.execute("DELETE FROM transactions WHERE user_id = ?", session["user_id"])
        session.clear()
        return redirect("/")
    else:
        return render_template("delete.html")