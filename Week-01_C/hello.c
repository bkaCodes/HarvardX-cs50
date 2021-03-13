#include <stdio.h>
#include <cs50.h>
//style50 - checks styling
//check50 - syntax for running associted unit tests for code problems

int main(void)
{
    //greet the user
    string answer = get_string("Hi! What's your name?\n");
    printf("hello %s! \n", answer);
}