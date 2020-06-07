#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // Input credit card number from user
    string input = NULL;
    do
    {
        input = get_string("Number: ");
    }
    while (atol(input) < 0);

    int n = strlen(input);
    unsigned int copy[n + 2];
    unsigned int save[n + 1];
    copy[n + 2] = 0;

    // Luhn's Algorithm

    // Copy the input into 2 arrays of integers
    for (int i = 0; i <= n; i++)
    {
        copy[i] = input[i] - 48;
        save[i] = input[i] - 48;
    }
    for (int i = n - 2; i >= 0; i -= 2)
    {
        copy[i] = copy[i] * 2;
        if (copy[i] > 9)
        {
            copy[i] = ((copy[i] - (copy[i] % 10)) / 10) + (copy[i] % 10);
        }
    }
    for (int i = 0; i < n; i++)
    {
        copy[n + 2] += copy[i];
    }

    // Result of algorithm
    if ((copy[n + 2] % 10) == 0)
    {
        // American Express card number
        if (save[0] == 3 && (save[1] == 4 || save[1] == 7) && n == 15)
        {
            printf("AMEX\n");
            return 0;
        }
        // Visa card number
        else if (save[0] == 4 && (n == 13 || n == 16))
        {
            printf("VISA\n");
            return 0;
        }
        // Mastercard card number
        else if (save[0] == 5 && (save[1] == 1 || save[1] == 2 || save[1] == 3 || save[1] == 4 || save[1] == 5))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}
