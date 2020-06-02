#include <cs50.h>
#include <stdio.h>

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



// Function for the hash marks
void mario(int height)
{

    for (int row = 0; row < height; row++)
    {
        // Sets the spaces on the left block of hash marks
        for (int space = row; space < height - 1; space++)
        {
            printf(" ");
        }

        // Controls the left block
        for (int hashL = 0; hashL <= row; hashL++)
        {
            printf("#");
        }

        // Space between left and right blocks
        printf("  ");

        // Controls the right block
        for (int hashR = 0; hashR <= row; hashR++)
        {
            printf("#");
        }
        printf("\n");
    }
}
