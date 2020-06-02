#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checks if command-line arg takes 2 words, if not ends program
    if (argc != 2)
    {
        printf("Command-line argument: 2 words\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    for (int n = 0, u = strlen(key); n < u; n++)
    {
        // Key length input (26 characters)
        if (isalpha(key[n]) && strlen(key) != 26)
        {
            // Key length error
            printf("Invalid key: Must contain 26 characters.\n");
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else if (!isalpha(key[n]))
        {
            // Invalid character(s) error
            printf("Invalid key: Only letters\n");
            printf("Usage: ./substitution key\n");
            return 1;
        }
        else
        {
            // Duplicate characters in the key
            int j = 0;
            for (int m = 0, p = strlen(key); m < p; m++)
            {
                if (toupper(key[n]) == toupper(key[m]))
                {
                    j++;
                }
            }

            if (j != 1)
            {
                printf("Invalid key: Duplicate character(s)\n");
                printf("Usage: ./substitution key\n");
                return 1;
            }

        }
    }



    // Prompts the user for input
    string pt = get_string("Plaintext:  ");

    // Encrypts the message
    for (int i = 0, s = strlen(pt); i < s; i++)
    {
        // For lowercase letters
        if (islower(pt[i]))
        {
            pt[i] = tolower(key[pt[i] - 97]);
        }

        // For uppercase letters
        else if (isupper(pt[i]))
        {
            pt[i] = toupper(key[pt[i] - 65]);
        }
    }


    // Prints ciphertext
    printf("ciphertext: %s\n", pt);

    return 0;
}
