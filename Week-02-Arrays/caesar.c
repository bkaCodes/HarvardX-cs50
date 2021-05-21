#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char encrypt(int shift, char current);
int check_letter(char text_char);

int main(int argc, char *arg_values[])
{
    //sanity checks on arguments - need to only have one argument passed to the program
    if ((argc < 2) || (argc > 2))
    {
        printf("ERROR Incorrect arguments passed. Usage: ./caesar key (where key is a singular integer value)\n");
        return 1;
    }

    //the first argument passed is the key or shift value for the cipher
    char *key = arg_values[1];

    //check if any of the characters in the passed key are non decimal values
    for (int i = 0; i < strlen(key); i++)
    {
        if ((key[i] < 48) || (key[i] > 57))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //convert the key to the integer value
    int shift = atoi(key);

    //prompting for the input to be encrypted
    string text = get_string("plaintext: ");

    //returning the encrypted text
    printf("ciphertext: ");

    //looping though the text - if non alphabetical, leave alone
    for (int i = 0; i < strlen(text); i++)
    {
        char letter = text[i];

        //first step is to check if the character is a letter or not
        if (1 == check_letter(letter))
        {
            printf("%c", encrypt(shift, letter)); //if yes, encypt
        }
        else
        {
            printf("%c", letter); //if not, leave be
        }
    }

    printf("\n"); //final new line

    return 0; //sucessfully completed

}


//encryption cipher
char encrypt(int shift, char current)
{

    char offset;

    if (islower(current))
    {
        offset = 'a';
    }
    else
    {
        offset = 'A';
    }

    return offset + ((current - offset + shift) % 26);
}

//check if a letter or not - returns 1 if letter, 0 otherwise
int check_letter(char text_char)
{
    //initialize default return value at 0
    int is_char = 0;
    char offset;

    //get the offset for alphabet characters
    if (islower(text_char))
    {
        offset = 'a';
    }
    else
    {
        offset = 'A';
    }

    //now check if the passed character is in the alphabet of not
    if (((text_char - offset) < 26) && ((text_char - offset) > -1))
    {
        is_char += 1;
    }

    return is_char;
}