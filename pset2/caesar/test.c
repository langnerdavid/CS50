#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main (void)
{
    string plaintext = get_string("plaintext: ");
    string cipher;
    for(int a = 0, n = strlen(plaintext); a < n; a++)
    {
        plaintext[a] = plaintext[a] + 1;
    }

    printf("%s\n", plaintext);

}