#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Please provide an integer value for x: \n");
    int y = get_int("Please provide an integer value for y: \n");
    printf("Added together: %i \n", x+y);
}

int divide(void)
{
    int x = get_int("Please provide an integer value for x: \n");
    int y = get_int("Please provide an integer value for y: \n");
    printf("Divided: %f \n",x/ (float) y); //casting y to a new type - this is the syntax
    return x/ (float) y; //note non void needs a return
}

//increment counter
//counter++; counter+=1; counter = counter + 1;

