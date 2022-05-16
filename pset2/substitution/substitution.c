#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


//get a encrypt key from the user
int main(int argc, string argv[])
{



    //Check if the key is valid
    //First condition: 2 commands, see if there is a key
    if (argc == 2)
    {
        string key = argv[1];
        //Check if there are duplicates
        int duplicates = 0;
        for(int i = 0; key[i] != '\0'; i++)
        {
            for(int j = 0; key[j] != '\0'; j++)
            {
                if(key[i] == key[j])
                {
                    duplicates ++;
                }
            }
        }


        //Check
        int len = strlen(key);

        //For every letter in the key ad 1 to i
        int i = 0;
        while (isalpha(key[i]))
        {
            i++;
        }


        //if therer are 26 letters in the key, the key is valid
        if (i == len && i == 26 && duplicates == 26)
        {

            //get a plaintext from the user
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");

            //check every letter
            for(int a= 0, n = strlen(plaintext); a < n; a++)
            {
                //if there is a letter in the plaintext decrypt it with the key
                if(isalpha(plaintext[a]))
                {
                    //first decide if its an upper or a lower case letter
                    if(isupper(plaintext[a]))
                    {
                        int pos = plaintext[a] - 'A';
                        char letter = key[pos];
                        if(islower(letter))
                        {
                            letter = toupper(letter);
                        }
                        //plaintext[a] = lettter;
                        printf("%c", letter);

                    }
                    else if(islower(plaintext[a]))
                    {
                        int pos = plaintext[a] - 'a';
                        char letter = key[pos];
                        if(isupper(letter))
                        {
                            letter = tolower(letter);
                        }
                        //plaintext[a] = lettter;
                        printf("%c", letter);
                    }
                }
                //if there is a char in the plaintext which isnt a letter than just leave it like that
                else
                {
                    printf("%c", plaintext[a]);
                }
            }


            printf("\n");
            return 0;
        }
        // if there are not 26 letters the key is invalid
        else if (i == len & i != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

}