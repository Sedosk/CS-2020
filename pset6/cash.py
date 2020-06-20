# Calculate the minimum number of coins required to give a user change

from cs50 import get_float
from math import floor


def main():

    # User input for change owed in dollars (require positve)
    while True:
        dollars = get_float("Change owed: ")
        if dollars < 0:
            continue
        else:
            break

    # Algorithm
    cents = round(dollars * 100)
    quarters = floor(cents / 25)
    dimes = floor((cents - quarters * 25) / 10)
    nickels = floor((cents - quarters * 25 - dimes * 10) / 5)
    pennies = floor((cents - quarters * 25 - dimes * 10 - nickels * 5))

    print(f"{quarters + dimes + nickels + pennies}")


main()
