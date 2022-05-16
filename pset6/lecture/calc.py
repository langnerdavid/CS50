try:
    x = int(input("x: "))
except ValueError:
    print("That is not an int!")
    exit()

try:
    y = int(input("x: "))
except ValueError:
    print("That is not an int!")
    exit()

print(x + y)