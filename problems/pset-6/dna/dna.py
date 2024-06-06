import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    # Read database file into a variable
    database_filename = sys.argv[1]
    with open(database_filename, newline='') as database_file:
        reader = csv.DictReader(database_file)
        database = list(reader)

    # Read DNA sequence file into a variable
    sequence_filename = sys.argv[2]
    with open(sequence_filename, 'r') as sequence_file:
        dna_sequence = sequence_file.read().strip()

    # Find longest match of each STR in DNA sequence
    strs = list(database[0].keys())[1:]  # Extract STR names from the database header
    str_counts = {str_: longest_match(dna_sequence, str_) for str_ in strs}

    # Check database for matching profiles
    for person in database:
        match = all(str_counts[str_] == int(person[str_]) for str_ in strs)
        if match:
            print(person['name'])
            return

    print("No match")
    return


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
