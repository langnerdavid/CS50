#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Get Text input from user
    string text = get_string("Text: ");
    //Count letter & words of the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);


    //calculate average letters & sentences
    float L = letters * (100 / (float) words);
    float S = sentences * (100 / (float) words);

    //Calculate the grade level with the Coleman-Liau Index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    //Print out the Grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        int grade = round(index);
        printf("Grade %i\n", grade);
    }

}



int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences ++;
        }
    }
    //printf("%i sentence(s)\n", sentences);
    return sentences;
}

int count_words(string text)
{
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    //printf("%i word(s)\n", words);
    return words;

}


int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isupper(text[i]) || islower(text[i]))
        {
            letters ++;
        }
    }
    //printf("%i letter(s)\n", letters);
    return letters;
}