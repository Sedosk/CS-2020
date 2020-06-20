# print pyramid using "#"

from cs50 import get_int


def main():

    # User input for half-pyramid size (max size is 8)
    while True:
        height = get_int("Height: ")
        if (height > 0 and height < 9):
            break

    # Algorithm
    mario(height)


def mario(height):
    hashes = 1
    space = height - 1
    for row in range(height):

        # print spaces before the hashes
        print(" " * space, end="")
        space -= 1

        # print left column hashes
        print("#" * hashes, end="")

        # print space inbetween columns
        print("  ", end="")
    
        # print right column hashes
        print("#" * hashes)
        hashes += 1
    

main()
