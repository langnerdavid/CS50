#include <cs50.h>
#include <stdio.h>


float average(int length, int array[]);

int main(void)
{
    int number = get_int("How many scores do yoiu have? ");
    int scores[number];
    for (int i = 0; i < number; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average : %f\n", average(number, scores));
}


float average(int length, int array[])
{
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum/ (float) length;
}