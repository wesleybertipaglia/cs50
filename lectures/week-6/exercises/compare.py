x = input("Enter a number: ")
y = input("Enter another number: ")

x = round(float(x), 2)
y = round(float(y), 2)

if x < y:
    print(f"{x} is less than {y}.")
elif x > y:
    print(f"{x} is greater than {y}.")
else:
    print(f"{x} is equal to {y}.")