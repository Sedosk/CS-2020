#include <cs50.h>
#include <stdio.h>

// Function prototype
void mario(int height);

int main(void)
{
    // Input of height is between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    mario(height);
}

void mario(int height)
{

    for (int row = 0; row < height; row++)
    {
        // Print spaces before the hashes
        for (int space = row; space < height - 1; space++)
        {
            printf(" ");
        }

        // Print the hashes
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        printf("\n");
    }
}
