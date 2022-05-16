#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask user for their name and greet them
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}