#include <stdio.h>
#include <cs50.h>

void blocks_symm(int height, int pad);

int main(void)
{
    int height = 0;
    while (height < 1 | height > 8)
    {
        height = get_int("Height: ");
    }


    for (int i = 1; i <= height; i++)
    {
        blocks_symm(i, height - i);

    }

}

void blocks_symm(int height, int pad)
{
    for (int i = 1; i <= pad; i++)
    {
        printf(" ");
    }

    for (int i = 1; i <= height; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 1; i <= height; i++)
    {
        printf("#");
    }

    printf("\n");
}

//    do
//   {
//        int height = get_int("Height: ");
//    }
//    while (height < 1 | height > 8);
