from sys import argv, exit
from pathlib import Path
import csv
import re

# Global variables
STRs = []


def main():

    # Command-line argument
    argc = len(argv)

    # Exit if argc is not 3
    if argc != 3:
        print("Usage: dna.py databases/[DATABASE] sequences/[SEQUENCE]")
        exit(1)

    # Open and read DNA sequence file
    sqfile = open(argv[2])
    sq = sqfile.read()
    sqlen = len(sq)
    sqfile.close()

    # Open and read DNA database file
    with open(argv[1]) as dbfile:
        file = csv.reader(dbfile)
        for row in file:
            STRs = row
            STRs.pop(0)
            strlen = len(STRs)
            break

        # Algorithm to count max STRs:
        #
        #       Look for different STRs (for loop in line 48)
        #   in DNA sequence (sq) in chunks of size len(i).
        #
        #       Compare the chunks to a particular STR (i) if there is
        #   a match increment counter, and skip len(i) places in sq.
        #   Else reset counter and skip 1 place in sq.
        #
        #       If counter is greater or equal than max count (maxc)
        #   update maxc.
        #
        #       Append maxc value to a list (max_list).
        #
        #       Reset all variables and continue to next STR.
        #
        max_list = []
        for i in STRs:
            j = 0
            counter = maxc = 0
            while j < sqlen:
                if sq[j:j + len(i)] == i:
                    counter += 1
                    if counter >= maxc:
                        maxc = counter
                    j += len(i)
                else:
                    counter = 0
                    j += 1
            max_list.append(maxc)

        # Convert max_list values from int to string.
        k = 0
        while k < strlen:
            max_list[k] = str(max_list[k])
            k += 1

        # Algorithm to compare values from max_list
        # to DNA database values
        #
        for pp in file:
            ps = pp.copy()
            i = 1
            counter = 0
            while i < len(ps):
                if ps[i] == max_list[i - 1]:
                    counter += 1
                i += 1
            if counter == len(max_list):
                print(ps[0])
                exit(0)
            else:
                ps.clear()
                continue
        print("No match")


main()
