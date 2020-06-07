// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node

{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 65536; 

// Hash table
node *table[N];

// Global variables
int word_count = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    /* make a copy of the word and pass */
    /* every letter to lowercase        */
    char copy[LENGTH + 1];
    for (int i = 0, n = strlen(word); i <= n; i++)
    {
        copy[i] = tolower(word[i]);
    }

    // Hash word from text and check if it is in respective linked list
    int j = hash(copy);
    for (node *csr = table[j]; csr != NULL; csr = csr->next)
    {
        if (strcasecmp(csr->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    /* Hashing algorithm */
    /* from http://www.cse.yorku.ca/~oz/hash.html (djb2) */
    unsigned long hashval = 7573;
    int c;
    while ((c = *word++))
    {
        hashval = ((hashval << 5) + hashval) + c; /* hashval * 33 + c */
    }
    int hashcode = hashval % N;

    return hashcode;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char save[LENGTH + 1];

    // Open dictionary file
    FILE *inptr = fopen(dictionary, "r");
    if (inptr == NULL)
    {
        return false;
    }
    while (true)
    {
        // Read dictionary file, word by word and save it in 'save'
        fscanf(inptr, "%s", save);

        // Check file end and break while loop
        if (feof(inptr))
        {
            fclose(inptr);
            return true;
        }

        // Create a new node for every word of dictionary file
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, save);

        // Hash word and add to start of linked list
        int j = hash(n->word);
        n->next = table[j];
        table[j] = n;

        word_count++;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return word_count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Unload dictionary from memory
    int counter = 0;
    for (int hc = 0; hc <= N; hc++)
    {
        node *csr = table[hc];

        while (csr != NULL)
        {
            node *tmp = csr;
            csr = csr->next;
            free(tmp);
            counter++;
        }
    }
    if (counter == word_count)
    {
        return true;
    }

    return false;
}

