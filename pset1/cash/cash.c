#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main()
{
    // Asks for user input (positive real numbers) 
    float dollars;
    do
    {
        dollars = get_float("Change owed : ");
    }
    while (dollars < 0);
    
    // Rounds up the decimal places (C overflow)
    int cents = round(dollars * 100);

    // Math part of source code
    int tfvc = cents / 25;   
    int tenc = (cents % 25) / 10;
    int fivc = ((cents % 25) % 10) / 5;
    int onec = ((cents % 25) % 10) % 5;

    // Displays the minimum amount of coins needed to give the inputed change
    printf("%d\n", tfvc + tenc + fivc + onec);
}

