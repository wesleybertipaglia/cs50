people = [
    {"name": "Carter", "phone": "123-456-7890"},
    {"name": "David", "phone": "234-567-8901"},
    {"name": "John", "phone": "345-678-9012"}
]

name = input("Enter a name: ")

def find_person(name):
    for person in people:
        if person["name"] == name:
            return person
    return None

person = find_person(name)

if person:
    print(f"Phone: {person['phone']}")
else:
    print("Person not found.")