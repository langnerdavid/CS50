#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //Get Credit Card number from user
    long number;
    do
    {
        number = get_long("Credit card number: ");
    }
    while (number <= 0);


    long checksum = 0;
    long checksum1 = 0;
    long checksum2 = 0;
    int length = 1;
    long num1 = 0;
    long num2 = 0;
    long cnumber = number;
    long anumber = number;
    long bnumber = number;
    long dnumber = number;

    //Count length of the number
    for (long count = number; count >= 10; count /= 10)
    {
        length ++;
    }

    //First step of Luhn's Algorithm
    do
    {
        num1 = (number % 100) / 10;
        num1 *= 2;

        if (num1 < 10)
        {
            checksum1 += num1;
        }
        else if (num1 >= 10)
        {
            num2 = (num1 % 10);
            checksum1 += (num2 + 1);
        }
        number /= 100;
    }
    while (number >= 10);

    //Second step of Luhn's Algorithn
    do
    {
        num2 = (cnumber % 10);
        checksum2 += num2;
        cnumber /= 100;
    }
    while (cnumber > 0);

    //Add both numbers together and check if the last digit is 0
    checksum = (checksum1 + checksum2);


    //Look at the length of the number
    //Check if its a AMEX card
    if (length == 15 && (checksum % 10) == 0)
    {
        for (int i = 0; i < 13; i++)
        {
            anumber /= 10;
        }

        if (anumber == 34 || anumber == 37)
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //Check 16 digits if its a VISA or MASTERCARD
    else if (length == 16 && (checksum % 10) == 0)
    {
        for (int i = 0; i < 14; i++)
        {
            bnumber /= 10;
        }

        if (bnumber >= 40 && bnumber <= 49)
        {
            printf("VISA\n");
        }
        else if (bnumber >= 51 && bnumber <= 55)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //Check if its a VISA Card
    else if (length == 13 && (checksum % 10) == 0)
    {
        for (int i = 0; i < 12; i++)
        {
            dnumber /= 10;
        }
        if (dnumber == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }

}