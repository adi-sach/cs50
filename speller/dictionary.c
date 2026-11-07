// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char low[LENGTH + 1];

    for (int i = 0; word[i]; i++)
    {
        low[i] = tolower(word[i]);
        low[i+1] = '\0';
    }

    unsigned int index = hash(low);
    node *cursor = table[index];

    while (cursor != NULL)
    {
        if (strcmp(cursor->word, low) == 0)
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
    int c1 = tolower(word[0]) - 'a';
    int c2 = word[1] ? tolower(word[1]) - 'a' :0;


    return (c1 * 26 + c2) % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 1];

    while (fscanf(source , "%s", word) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(source);
            return false;
        }

        strcpy(n->word, word);

        unsigned int index = hash(word);

        n->next = table[index];
        table[index] = n;

        word_count++;
    }
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp =  cursor;
            cursor = cursor->next;
            free(tmp);
        }
        table[i] = NULL;
    }
    return true;
}
