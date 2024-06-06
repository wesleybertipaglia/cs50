s = input("Do you agree? ")

if s.lower() in ["y", "yes", "yeah", "yep"]:
    print("Agreed.")
elif s.lower() in ["n", "no", "nope", "nah"]:
    print("Not agreed.")