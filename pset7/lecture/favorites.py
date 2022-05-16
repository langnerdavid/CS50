import csv

#set = duplicates filtered out
titles = {}

with open("favorites.csv", "r") as file:
    reader = csv.reader(file)
    for row in reader:
        title = row["title"].strip().upper()
        if tile in titles:
            titles[title] += 1
        else:
            titles[title] = 1


for title in sorted(titles, key=lambda title: titles[title]):
    print(title, titles[title])