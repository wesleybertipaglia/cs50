import sqlite3
from flask import Flask, render_template, request, session
from uuid import uuid4
from werkzeug.security import generate_password_hash, check_password_hash

app = Flask(__name__)
app.secret_key = 'your_secret_key'
app.config['SESSION_PERMANENT'] = False
app.config['SESSION_TYPE'] = 'filesystem'

def init_db():
    with sqlite3.connect("froshims.db") as con:
        cur = con.cursor()
        cur.execute('CREATE TABLE IF NOT EXISTS sports (id TEXT PRIMARY KEY, name TEXT)')
        cur.execute('CREATE TABLE IF NOT EXISTS students (id TEXT PRIMARY KEY, name TEXT, username TEXT UNIQUE, password TEXT, sport TEXT)')
        if not cur.execute("SELECT 1 FROM sports").fetchone():
            sports = [
                ('1', 'Basketball'),
                ('2', 'Football'),
                ('3', 'Soccer'),
                ('4', 'Tennis'),
                ('5', 'Volleyball')
            ]
            cur.executemany("INSERT INTO sports (id, name) VALUES (?, ?)", sports)
        con.commit()

with app.app_context():
    init_db()

@app.route('/')
def index():
    user_id = session.get('user_id')
    if user_id:
        try:
            with sqlite3.connect("froshims.db") as con:
                con.row_factory = sqlite3.Row
                cur = con.cursor()
                student = cur.execute("SELECT * FROM students WHERE id = ?", (user_id,)).fetchone()
        except sqlite3.Error as e:
            return render_template('failure.html', message=f'Database error: {e}')
        return render_template('index.html', student=student)
    return render_template('index.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        name = request.form.get('name')
        username = request.form.get('username')
        password = request.form.get('password')
        sport = request.form.get('sport')
        
        if not name:
            return render_template('failure.html', message='You must provide your name.')
        elif not username:
            return render_template('failure.html', message='You must provide your username.')
        elif not password:
            return render_template('failure.html', message='You must provide your password.')
        elif not sport:
            return render_template('failure.html', message='You must provide your favorite sport.')

        hashed_password = generate_password_hash(password)

        try:
            with sqlite3.connect("froshims.db") as con:
                cur = con.cursor()
                cur.execute("INSERT INTO students (id, name, username, password, sport) VALUES (?, ?, ?, ?, ?)", 
                            (str(uuid4()), name, username, hashed_password, sport))
                con.commit()
        except sqlite3.Error as e:
            return render_template('failure.html', message=f'Database error: {e}')
        return render_template('success.html', message=f'Thank you {name} for registering!')

    try:
        with sqlite3.connect("froshims.db") as con:
            con.row_factory = sqlite3.Row
            cur = con.cursor()
            sports = cur.execute("SELECT id, name FROM sports").fetchall()
    except sqlite3.Error as e:
        return render_template('failure.html', message=f'Database error: {e}')
    return render_template('register.html', sports=sports)

@app.route("/deregister", methods=["POST"])
def deregister():
    student_id = request.form.get("id")
    if student_id:
        try:
            with sqlite3.connect("froshims.db") as con:
                cur = con.cursor()
                cur.execute("DELETE FROM students WHERE id = ?", (student_id,))
                con.commit()
        except sqlite3.Error as e:
            return render_template('failure.html', message=f'Database error: {e}')
    return render_template('success.html', message='You have successfully deregistered!')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form.get('username')
        password = request.form.get('password')
        if not username:
            return render_template('failure.html', message='You must provide your username.')
        elif not password:
            return render_template('failure.html', message='You must provide your password.')

        try:
            with sqlite3.connect("froshims.db") as con:
                con.row_factory = sqlite3.Row
                cur = con.cursor()
                student = cur.execute("SELECT * FROM students WHERE username = ?", (username,)).fetchone()
                if not student or not check_password_hash(student['password'], password):
                    return render_template('failure.html', message='Invalid username or password.')
        except sqlite3.Error as e:
            return render_template('failure.html', message=f'Database error: {e}')
        session['user_id'] = student['id']
        return render_template('success.html', message='You have successfully logged in!')
    return render_template('login.html')

@app.route('/logout')
def logout():
    session.clear()
    return render_template('success.html', message='You have successfully logged out!')

@app.route('/students', methods=['GET'])
def registrants():
    try:
        with sqlite3.connect("froshims.db") as con:
            con.row_factory = sqlite3.Row
            cur = con.cursor()
            students = cur.execute("SELECT * FROM students").fetchall()
    except sqlite3.Error as e:
        return render_template('failure.html', message=f'Database error: {e}')
    return render_template('students.html', students=students)

if __name__ == '__main__':
    app.run(debug=True)
