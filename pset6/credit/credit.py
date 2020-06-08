# Determine whether a provided credit card number is valid according to Luhn’s algorithm

from cs50 import get_int
from math import floor
from sys import exit


def main():

    # User input
    number = get_int("Number: ")
    
    # Call to function
    credit(number)


def credit(number):

    # Copy input
    copy = number

    # Calculate number length
    numlen = 0
    while copy > 0:
        copy = floor(copy / 10)
        numlen += 1
    
    # Check number length    
    if (numlen != 13 and numlen != 15 and numlen != 16):
        print("INVALID")
        exit(0)

    # Restore copy of input
    copy = number
    
    calc2 = 0
    copy *= 10
    
    # Luhn's algorithm
    i = 0
    while i < numlen:
        
        # Imagine that the last digit is the 0th, second-to-last is the 1st, and so forth.
        # (counting from right to left)
    
        # Calculation for EVEN numbered digits
        copy = floor((copy / 10))           # Proceed to next digit
        calc1 = copy 
        calc1 %= 10                         # Isolate last digit
        calc2 += calc1                      # Update total
        
        # Calculation for ODD numbered digits
        copy = floor((copy / 10))           # Proceed to next digit
        calc1 = copy 
        calc1 %= 10                         # Isolate last digit
        calc1 *= 2
        tmp1 = calc1 % 10 
        tmp2 = floor(calc1 / 10) % 10
        calc1 = tmp1 + tmp2
        calc2 += calc1                      # Update total
        i += 2
    
    # Restore copy of input
    copy = number
    
    # Isolate first 2 digits (left to right)
    while copy > 100:
        copy = floor(copy / 10)
    num2 = (copy % 10)                      # First digit
    num1 = floor((copy / 10)) % 10          # Second digit

    # Result of algorithm
    if (calc2 % 10) == 0:
        # American Express card number
        if num1 == 3 and (num2 == 4 or num2 == 7) and numlen == 15:
            print("AMEX")
            exit(0)

        # Visa card number
        elif num1 == 4 and (numlen == 13 or numlen == 16):
            print("VISA")
            exit(0)
        
        # Mastercard card number
        elif num1 == 5 and (num2 == 1 or num2 == 2 or num2 == 3 or num2 == 4 or num2 == 5):
            print("MASTERCARD")
            exit(0)
        else:
            print("INVALID")
            exit(0)
    else:    
        print("INVALID")
        exit(0)


main()
