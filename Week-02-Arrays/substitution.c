#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int check_args(int argc, char *arg_values[]);
int check_valid_key(string sub_key);
int check_letter(char text_char);
char encrypt(string sub_key, char current);


int main(int argc, char *arg_values[])
{
    if (1 == check_args(argc, arg_values))
    {
        return 1;
    }

    //defining our substitution key
    char *sub_key = arg_values[1];


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
            printf("%c", encrypt(sub_key, letter)); //if yes, encypt
        }
        else
        {
            printf("%c", letter); //if not, leave be
        }
    }

    printf("\n"); //final new line

    return 0; //sucessfully completed

}

int check_args(int argc, char *arg_values[])
{
    //sanity checks on arguments - need to only have one argument passed to the program
    if ((argc < 2) || (argc > 2))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //the first argument passed is the substitution key for the cipher
    char *sub_key = arg_values[1];

    return check_valid_key(sub_key);

}


int check_valid_key(string sub_key)
{

    if (26 != strlen(sub_key))
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    //initialize default return value at 1
    int occurances[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int is_char = 1; //error
    char offset;

    //looping though the key - if non alphabetical error, if not all 26 alpabetical characters error
    for (int i = 0; i < strlen(sub_key); i++)
    {
        char text_char = sub_key[i];


        //get the offset for alphabet characters
        if (islower(text_char))
        {
            offset = 'a';
        }
        else
        {
            offset = 'A';
        }

        //printf("text_char: %c, offset: %c, num: %i\n", text_char, offset, text_char - offset);


        //check if the character is a letter or not
        if (((text_char - offset) > 26) || ((text_char - offset) < -1))
        {
            printf("Key must contain only alphabetic characters.\n");
            return 1;
        }

        //check if this letter has already appeared
        occurances[text_char - offset] += 1;
        if (occurances[text_char - offset] > 1)
        {
            printf("Key must contain all alphabet characters, exactly once.\n");
            return 1;
        }
    }

    return 0;

}

//encryption cipher
char encrypt(string sub_key, char current)
{

    char offset;
    int lowercase_char = islower(current);

    if (lowercase_char)
    {
        offset = 'a';
    }
    else
    {
        offset = 'A';
    }

    char key_sub = sub_key[(current - offset) % 26];
    int shift[] = {32, -32};

    //shifting for casing as needed
    if (lowercase_char != islower(key_sub))
    {
        //printf("key_sub: %c, key_int: %i, char: %c, current_char_int: %i, shift value: %i, new_key_val: %c\n", key_sub, key_sub, current, current, key_sub + lowercase_char ? 32 : -32, key_sub + (lowercase_char ? 32 : -32));
        key_sub = key_sub + (lowercase_char ? 32 : -32);
    }

    return key_sub;
}


//check if a letter or not - returns 1 if letter, 0 otherwise
int check_letter(char text_char)
{
    //initialize default return value at 1
    int is_char = 0; //error
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
        is_char = 1; //success
    }

    return is_char;
}