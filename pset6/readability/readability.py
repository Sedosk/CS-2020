# Computes the approximate grade level needed to comprehend some text

from cs50 import get_string
from sys import exit
import re
import string


def main():

    # Prompt user for input
    text = get_string("Text: ")

    # Counters
    l = s = i = 0
    w = 1

    n = len(text)

    # Iterate over each char of the text
    for i in range(n):
        # Count letters
        if text[i].isalnum() == True:
            l += 1
        # Count words
        elif text[i].isspace() == True:
            w += 1
        # Count sentences
        elif text[i] == '.' or text[i] == '?' or text[i] == '!':
            s += 1

    # Coleman-Liau index
    L = l / w * 100.000
    S = s / w * 100.000
    grade = round(0.0588 * L - 0.296 * S - 15.800)

    # Print grade readability
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


main()

