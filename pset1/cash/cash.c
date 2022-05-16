#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float cash;

    //Get money owed from user
    do
    {
        cash = get_float("How much $ do I owe you? ");
    }
    while (cash <=  0);

    //Convert dollars into cents
    int cents = round(cash * 100);


    int coins = 0;

    //Check how many coins the cashier has to give
    //After checking which is the biggest that fits into the owed money
    //Subtract that number and add 1 to the coins counter
    while (cents > 0)
    {
        if (cents >= 25)
        {
            cents -= 25;
            coins++;
        }

        else if (cents >= 10)
        {
            cents -= 10;
            coins ++;
        }

        else if (cents >= 5)
        {
            cents -= 5;
            coins ++;
        }

        else if (cents >= 1)
        {
            cents -= 1;
            coins ++;
        }
    }

    //Print out the minimum number of coins
    printf("Coins: %i\n", coins);

}