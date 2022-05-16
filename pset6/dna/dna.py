import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")

    # Read database file into a variable
    database = []
    with open(sys.argv[1]) as csv_file:
        reader = csv.DictReader(csv_file)
        for row in reader:
            database.append(row)



    # Read DNA sequence file into a variable
    with open(sys.argv[2], "r") as sequence:
        dna_sequence = sequence.read()

    #print(f"{dna_sequence}")


    # Find longest match of each STR in DNA sequence
    str_names = reader.fieldnames[1:]

    longest_number = []
    for str in str_names:
        longest_number.append(longest_match(dna_sequence, str))
    #print(f"{longest_number}")

    # Check database for matching profiles
    with open(sys.argv[1],) as file:
        reader_match = csv.reader(file)
        next(reader_match)[1:]
        for row in reader_match:
            max_number_person = []
            for number in row[1:]:
                max_number_person.append(int(number))
            #print(max_number_person)
            if max_number_person == longest_number:
                 print(row[0])
                 return
        print("No match")

    #return


def dna_match_person(row, str_names, dna_sequence):
    count = 0
    for str in str_names:
        if int(dna_sequence[str]) == int(row[str]):
            count += 1
    if count == len(str):
        return True
    else:
        return False

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
