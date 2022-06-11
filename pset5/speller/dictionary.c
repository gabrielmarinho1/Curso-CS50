// Implements a dictionary's functionality

#include <ctype.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 122;

//count words in dictionary
double count = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int a = hash(word);

    //compare the word with each ones in the dictionary and if it's there, return true
    for (node *tmp = table[a]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //return the first letter alphabetical position
    if (islower(word[0]))
    {
        return word[0] - 97;
    }
    else
    {
        return word[0] - 65;
    }
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    //open dictionary
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open file.\n");
        return false;
    }
    //word array
    char word[LENGTH + 1];

    //copy each word from the dictionary to the word array
    while (fscanf(dict, "%s", word) != EOF)
    {
        //malloc a new node for the word and copy into it
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
            return false;
        }
        strcpy(new->word, word);
        new->next = NULL;

        //get the hash index
        int position = hash(word);

        //if there's no words in that index currently, add the new word to be the head of the linked list
        if (table[position] == NULL)
        {
            table[position] = new;
        }
        //otherwise there is words in that index already, add the new word in top of it
        else
        {
            new->next = table[position];
            table[position] = new;
        }

        count++;
    }
    fclose(dict);
    return true;
}


// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor = NULL;
    // TODO
    for (int i = 0; i < N; i++)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = cursor)
        {
            cursor = tmp->next;
            free(tmp);
        }
    }
    return true;
}
