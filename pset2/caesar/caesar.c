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
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string key = argv[1];
    int keylen = strlen(key);
    int k = atoi(argv[1]);

    // Checks if command-line arg is an integer, if not ends program
    for (int n = 0; n < keylen; n++)
    {
        if (key[n] > '9' || key[n] < '1')
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Prompts the user for input
    string pt = get_string("Plaintext:  ");

    int ptlen = strlen(pt);

    // Encrypts the message
    for (int i = 0; i < ptlen; i++)
    {
        // For lowercase letters
        if (islower(pt[i]))
        {
            pt[i] = ((pt[i] - 97 + k) % 26) + 97;
        }

        // For uppercase letters
        else if (isupper(pt[i]))
        {
            pt[i] = ((pt[i] - 65 + k) % 26) + 65;
        }
    }

    // Prints encrypted text (ciphertext)
    printf("ciphertext: %s\n", pt);
    return 0;
}
