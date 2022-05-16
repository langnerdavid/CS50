#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//get a encrypt key from the user
int main(int argc, string argv[])
{
    int key;


    //Check if the key is valid
    //2 commands
    if (argc == 2)
    {
        int len = strlen(argv[1]);

        //For every digit in the key ad 1 to i
        int i = 0;
        while (isdigit(argv[1][i]))
        {
            i++;
        }


        //if all digits are numerical the key is valid
        if (i == len)
        {

            //convert key into an integer and print it out
            key = atoi(argv[1]);

            //get a plaintext from the user to enrcypt
            string plaintext = get_string("plaintext: ");

            printf("ciphertext: ");


            //check every char of the string
            for (int a = 0, n = strlen(plaintext); a < n; a++)
            {
                //1st if its a letter from the alphabet
                if (isalpha(plaintext[a]))
                {
                    //2nd if its uppercase
                    //if its uppercase than encypher it
                    if (isupper(plaintext[a]))
                    {
                        plaintext[a] -= 'A';
                        char c = (plaintext[a] + key) % 26;
                        c += 'A';
                        printf("%c", c);
                    }
                    //if its lowercase encypher it
                    else if (islower(plaintext[a]))
                    {
                        plaintext[a] -= 'a';
                        char c = (plaintext[a] + key) % 26;
                        c += 'a';
                        printf("%c", c);
                    }

                }
                //if it isnt a letter from alphabet than just leave it like that
                else
                {
                    printf("%c", plaintext[a]);
                }


            }

            printf("\n");
            return 0;
        }
        //if not all characters are numbers the key is invalid
        else
        {
            printf("Usage: ./caesar key");
            return 1;
        }

    }
    //if the key is invalid print that the user needs to type in a correct key
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}