#include <stdio.h>
#include <cs50.h>

int llama_pop();

int main(void)
{
    int start_pop = 0;
    int end_pop = 0;

    //getting starting and end population values
    //populations < 9 can't sustain any growth and will actually decline
    while (start_pop < 9)
    {
        start_pop = get_int("Start size: ");
    }
    //population grows so the end population must necessarily be bigger than the starting population
    while (end_pop < start_pop)
    {
        end_pop = get_int("End size: ");
    }

    //using the population growth formula recursively until we reach the a value bigger than the end population
    int years;
    for (years = 0; start_pop < end_pop; years++)
    {
        start_pop = llama_pop(start_pop);
    };

    printf("Years: %i \n", years);
}

//formula for llama population growth
int llama_pop(int current_pop)
{
    return current_pop + current_pop / 3 - current_pop / 4;
}
