import csv

title = input("Title: ").strip().upper()

counter = 0

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        if row["title"].strip().upper() == title:
            counter += 1

print(counter)