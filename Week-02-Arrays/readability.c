#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int check_letter(char text_char);
int cl_index(float avg_num_letters, float avg_num_sentences);
float two_places(float num);


//takes an input text and computes the reading age
int main(void)
{
    // Get input text from user
    string text = get_string("Text: ");
    int text_length = strlen(text);

    //lets define all the things we need to keep track of
    int tot_letters = 0;
    int tot_words = 1; //extra one for the ending word which doesn't have a space to indicate this relationship
    int tot_sentences = 0;

    //now we loop through the text and increment as we come to each of these things:
    // for words - when we come to a space we incrememt
    // for letters - just keeping a cumulative count
    // for sentences - when we come to a sentence ender like !?.
    //all else, no effect
    for (int i = 0; i < text_length; i++)
    {
        char text_char = text[i];
        int text_char_int = text_char - 0;

        tot_letters += check_letter(text_char);
        tot_words += (32 == text_char_int);
        tot_sentences += (33 == text_char_int) + (46 == text_char_int) + (63 == text_char_int);

        //printf("char: %c, cum_letters: %i, cum_words: %i, cum_sent: %i\n", text_char, tot_letters, tot_words, tot_sentences);

    }

    //printf("cum_letters: %i, cum_words: %i, cum_sent: %i\n", tot_letters, tot_words, tot_sentences);

    //have run though all the text now, it's time to compute the averages now.
    float avg_num_letters = (tot_letters / (float) tot_words) * 100; //average number of letters per 100 words in the text
    float avg_num_sentences = (tot_sentences / (float) tot_words) * 100; //average number of words per 100 sentences

    //printf("avg_let: %f, avg_sents: %f\n", avg_num_letters, avg_num_sentences);


    //compute the readability index
    int RI = cl_index(avg_num_letters, avg_num_sentences);


    if (RI < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (RI > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", RI);
    }


}

float two_places(float num)
{
    return (round(num * 100)) / 100.0;
}


//readability formula
int cl_index(float avg_num_letters, float avg_num_sentences)  //both averages are per 100 words
{

    float index = 0.0588 * avg_num_letters - 0.296 * avg_num_sentences - 15.8;
    //printf("Computed index %f\n", index);
    return round(index);
}


//checks for each character
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

