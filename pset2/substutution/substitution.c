#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Check if command-line arg takes 2 words, if not end program
    if (argc != 2)
    {
        printf("Command-line argument: 2 words\n");
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);

    for (int n = 0; n < keylen; n++)
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
            for (int m = 0; m < keylen; m++)
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

    // Prompt user for input
    string pt = get_string("Plaintext:  ");

    int ptlen = strlen(pt);

    // Encrypt message
    for (int i = 0; i < ptlen; i++)
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

    // Print ciphertext
    printf("ciphertext: %s\n", pt);

    return 0;
}
