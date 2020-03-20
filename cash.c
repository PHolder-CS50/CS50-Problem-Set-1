#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Given an input of the amount of change owed, calculate
// the minimum number of coins that will be given
int main(void)
{
    float amt;
    do
    {
        amt = get_float("Change owed: ");
    }
    while (amt < 0);

    int amtInCents = round(amt * 100);
    int numCoins = 0;
    while (amtInCents > 0)
    {
        if (amtInCents >= 25)
        {
            // change includes a quarter
            numCoins++;
            amtInCents -= 25;
        }
        else if (amtInCents >= 10)
        {
            // change includes a dime
            numCoins++;
            amtInCents -= 10;
        }
        else if (amtInCents >= 5)
        {
            // change includes a nickle
            numCoins++;
            amtInCents -= 5;
        }
        else
        {
            // the rest of the change is pennies
            numCoins += amtInCents;
            amtInCents = 0;
        }
    }
    printf("%i\n", numCoins);
}
