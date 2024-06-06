from sys import argv
import sys

def greet(name):
    print(f"Hello, {name}!")

if len(argv) == 2:
    greet(argv[1])
    sys.exit(0)
else:
    print("Usage: python greet.py name")
    sys.exit(1)