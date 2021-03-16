#include <stdio.h>
#include <cs50.h>
#include <math.h>

//first declare the denominations in an array - we will use this to iterate through
int denominations[] = {25, 10, 5, 1};

int main(void)
{
    float cash = -0.1;
    while (cash < 0)
    {
        cash = get_float("Change owed: ");
    }

    int cash_int = round(cash * 100);
    //counters
    int coins = 0;
    int denom = 0;

    //want to keep looping until the cash has all run out
    //loop through the denominations from largest to smallest
    while (cash_int > 0)
    {
        //if I have more less cash than my largest denomination move up the array to next smallest
        while (cash_int < denominations[denom])
        {
            denom++;
        }

        //reduce the cash by the denomination amount
        cash_int -= denominations[denom];
        //increase the number of coins
        coins++;
    }

    //once program is complete, return the total coin count
    printf("%i\n", coins);

}
