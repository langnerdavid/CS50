// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stddef.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

//Number of words
int words = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashcode = hash(word);
    node *cursor = table[hashcode];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int code = tolower(word[0]) - 'a';
    return code;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //Read into the given dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    //create buffer to store one word at a time
    char buffer [LENGTH + 1];
    //
    while (fscanf(file, "%s", buffer) != EOF)
    {
        //Allocate memory for new node
        node *n = malloc(sizeof(node));
        strcpy (n->word, buffer);
        if (n == NULL)
        {
            return false;
        }

        //Hash Word
        int num = hash(buffer);

        if (table[num] == NULL)
        {
            n->next = NULL;
            table[num] = n;
        }
        else
        {
            n->next = table[num];
            table[num] = n;
        }
        words++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor ->next;
            free(tmp);
        }
    table[i] = NULL;
    }
    return true;
}
