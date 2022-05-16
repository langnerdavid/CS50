#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");

    for(int i = 0, n = strlen(s); i < n; i++)
    {

        if(islower(s[i]))
        {
            printf("%c", toupper(s[i]));  //if only char this line would work
        }
        else
        {
            printf("%c", s[i]);
        }

        /* If ctype.h didnt exist:
            Readable but with the library its easier
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            printf("%c", s[i] - 32);
        }
        else
        {
            printf("%c", s[i]);
        }   */
    }
    printf("\n");
}