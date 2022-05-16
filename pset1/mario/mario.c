#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    //Get height between 1 and 8 from user
    do
    {
        height = get_int("Height of the pyramid: ");
    }
    while (height > 8 || height < 1);

    //Print out the pyramide
    int x = height;
    for (int i = 0; i < x; i++)
    {
        //Print the spaces before #
        for (int space = height - 1; space > 0; space--)
        {
            printf(" ");
        }
        height --;

        //Print # and go to next line
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        //Print the right side of the Pyramide with the spaces between
        printf("  ");
        for (int h = 0; h <= i; h++)
        {
            printf("#");
        }
        printf("\n");
    }
}