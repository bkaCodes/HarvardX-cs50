#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int luhns_algo(char *cardstr, int length);
void card_type(char *cardstr);

int main(void)
{
    long cardno;
    do
    {
        cardno = get_long("Number: ");
    }
    while (cardno < 0);

    //card numbers are between 13 - 16 digits
    if (cardno < 1000000000000 | cardno > 9999999999999999)
    {
        printf("INVALID\n");
        return 0;
    }

    //store in a string as that makes most sense when adding digits, not full numbers
    char cardstr[16];
    int length = sprintf(cardstr, "%ld", cardno);

    //we pass through the length so we iterate correctly
    int checksum = luhns_algo(cardstr, length);
    // printf("checksum from luhns: %i, length: %i\n", checksum, length);

    if (0 != checksum % 10)
    {
        printf("INVALID\n");
    }
    else
    {
        card_type(cardstr);
    }

}

void card_type(char *cardstr)
{
    int first_digit = cardstr[0] - '0';
    int second_digit = cardstr[1] - '0';

    //card types - VISA start with 4
    // AMEX either 34 or 37
    // MASTERCARD between 51 - 55
    if (first_digit == 4)
    {
        printf("VISA");
    }
    else if ((first_digit == 3) && ((second_digit == 4) || (second_digit == 7)))
    {
        printf("AMEX");
    }
    else if ((first_digit == 5) && ((second_digit > 0) && (second_digit < 6)))
    {
        printf("MASTERCARD");
    }
    else
    {
        printf("INVALID");
    }
    printf("\n");
}


int luhns_algo(char *cardstr, int length)
{
    int num[8] = {};
    char str[16];
    int str_n = 0;
    int sum = 0;

    //want to start from the second from last and increment along, doubling as we go and storing in a string to revert back to digits
    for (int card_ind = length - 2, j = 0 ; card_ind >= 0 ; card_ind -= 2, j += 1)
    {
        num[j] = 2 * (cardstr[card_ind] - '0');
        str_n += sprintf(&str[str_n], "%i", num[j]);
    }

    //for the checksum we now need to loop through the created string and add all digits
    for (int i = 0; i < str_n; i++)
    {
        sum += str[i] - '0';
    }

    //the secondary sum is the just other digits that weren't used before
    //potential optimzation - if's in the other statement to account for the edge lengths
    for (int card_odd_ind = length - 1; card_odd_ind >= 0; card_odd_ind -= 2)
    {
        sum += cardstr[card_odd_ind] - '0';
    }

    return sum;
}