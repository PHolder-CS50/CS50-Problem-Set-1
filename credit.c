#include <stdio.h>
#include <cs50.h>

long getPotentialCCNum();
bool isValidLuhnChecksum(long potentialCCnum);
string getTypeOfCC(long potentialCCnum);

int main(void)
{
    long potentialCCnum = getPotentialCCNum();
    if (isValidLuhnChecksum(potentialCCnum))
    {
        printf("%s\n", getTypeOfCC(potentialCCnum));
    }
    else
    {
        printf("INVALID\n");
    }
}

// Input a potential CC number from the user
long getPotentialCCNum()
{
    return get_long("Number: ");
}

// Use Luhn’s algorithm to make sure the CC is valid 
bool isValidLuhnChecksum(long potentialCCnum)
{
    int digitnum = 0;
    int checksum = 0;
    while (potentialCCnum > 0)
    {
        int digit = potentialCCnum % 10;
        digitnum++;
        if (digitnum % 2 == 0)
        {
            // For even numbers, multiply by 2 and add the digits together
            // Since the maximum is 9*2 = 18, always add the one's digit and
            // then check if the sum is ten or greater to add one more
            checksum += digit * 2 % 10;
            if (digit * 2 > 9)
            {
                checksum++;
            }
        }
        else
        {
            checksum += digit;
        }
        potentialCCnum /= 10;
    }
    return checksum % 10 == 0;
}

// To determine the CC type, check the length and the starting digit or 2 digits
string getTypeOfCC(long potentialCCnum)
{
    // calculate the first two digits and the total number of digits
    int digit1 = 0;
    int digit2 = 0;
    int numdigits = 0;
    while (potentialCCnum > 0)
    {
        digit2 = digit1;
        digit1 = potentialCCnum % 10;
        numdigits++;
        potentialCCnum /= 10;
    }

    // AMEX has 15 digits, starting with 34 or 37
    if (numdigits == 15)
    {
        if (digit1 == 3)
        {
            if (digit2 == 4 || digit2 == 7)
            {
                return "AMEX";
            }
        }
    }

    // VISA has 13 or 16 digits, starting with 4
    if (numdigits == 13 || numdigits == 16)
    {
        if (digit1 == 4)
        {
            return "VISA";
        }
    }

    // MC 16 digits, starting with 51, 52, 53, 54 or 55
    if (numdigits == 16)
    {
        if (digit1 == 5)
        {
            if (digit2 > 0 && digit2 < 6)
            {
                return "MASTERCARD";
            }
        }
    }

    return "INVALID";
}
