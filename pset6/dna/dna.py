import csv
import sys


def main():
    # TODO: Check for command-line usage

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # TODO: Read database file into a variable

    database = []

    with open(sys.argv[1]) as data:  # Open the database
        reader = csv.DictReader(data)  # Read every line of the database as a single dictionary
        for line in reader:  # For each dict in reader
            for key in line.keys():  # Loop through each key in line
                if key != "name":
                    line[key] = int(line[key])  # Convert the STRs values to int
            database.append(line)  # Append each dict in the dict-list database

    # TODO: Read DNA sequence file into a variable

    with open(sys.argv[2]) as dna:  # Open sequence
        sequence = dna.read()  # Read DNA sequence into memory

    # TODO: Find longest match of each STR in DNA sequence

    count = {}  # Count the STRs matches
    for line in database:  # For each dict in database
        for key in line.keys():  # For each key in dict
            if key != "name":
                longest = longest_match(sequence, key)  # Get the longest match for each STR
                count[key] = longest  # Store the STR count

    # TODO: Check database for matching profiles

    for person in database:  # For each dict in database
        matches = 0  # Count STR matches
        for key in person.keys():  # For each STR in dict
            if key != "name":
                if person[key] != count[key]:
                    break
                else:
                    matches += 1  # Count 1 match if the longests matches are equal

        if matches == len(count):  # If person have the same matches than the sequence, print their name
            print(person["name"])
            exit()

    print("No match")  # Whether, there ain't no people compatible, print No match and exit
    exit()


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
