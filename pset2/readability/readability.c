#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Prompt user for input
    string text = get_string("Text: ");

    /* Detect and count each char of the text,
       and separate in 3 categories */
    int l = 0;
    int w = 1;
    int s = 0;

    for (int n = 0, i = strlen(text); n < i; n++)
    {
        // Count letters
        if (isalnum(text[n]))
        {
            l++;
        }

        // Count words
        else if (isblank(text[n]))
        {
            w++;
        }

        // Count sentences
        else if (ispunct(text[n]))
        {
            if (text[n] == '.' || text[n] == '!' || text[n] == '?')
            s++;
        }
    }
   
    // Coleman-Liau index
    int L = round(100.000 * (float) l / w);
    int S = round(100.000 * (float) s / w);
    int grade = round(0.0588 * L - 0.296 * S - 15.800);

    // Print grade readability
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    
    return 0;
}
