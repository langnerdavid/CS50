from cs50 import get_string

people = {
    "Carter": "6546516384654",
    "David": "32576879"
}

name = get_string("Name: ")
if name in people:
    print(f"Number: {people[name]}")