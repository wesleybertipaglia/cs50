def add(x, y) -> float:
    """Adds two numbers."""
    return round(float(x) + float(y), 2)

def subtract(x, y) -> float:
    """Subtracts two numbers."""
    return round(float(x) - float(y), 2)

def multiply(x, y) -> float:
    """Multiplies two numbers."""
    return round(float(x) * float(y), 2)

def divide(x, y) -> float:
    """Divides two numbers, handling division by zero."""
    try:
        return round(float(x) / float(y), 2)
    except ZeroDivisionError:
        return "Division by zero is not allowed."

x = input("Enter a number: ")
y = input("Enter another number: ")

print(f"{x} + {y} = {add(x, y)}")
print(f"{x} - {y} = {subtract(x, y)}")
print(f"{x} * {y} = {multiply(x, y)}")
print(f"{x} / {y} = {divide(x, y)}")
