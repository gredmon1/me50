// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

#include "dictionary.h"


// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

// Hash table
node *table[N];

int count;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    
    
    int hash_index = hash(word);
    
    node *head = table[hash_index];
    node *tmp = head;
    
    
    while(tmp != NULL)
    {
        if(strcasecmp(word, tmp->word) == 0)
        {
            int wordl = strlen(tmp->word);
            
            for(int i = 0; i <= wordl; i++)
            {
                if (word[i] == 39 && tmp->word[i] == 39)
                {
                    return true;
                    tmp = tmp->next;
                    
                }

            
            }
            return true;
            
        }
        else
        {
            return false;
            tmp = tmp->next;
        }
    }
    return true;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    //djb2 hash algorithm, url: http://www.cse.yorku.ca/~oz/hash.html
    unsigned long hash = 5381;
    
    int c = 0;

    while (c == *word++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    
    // TODO
   FILE *dict_file = fopen(dictionary, "r");
   bool isloaded = false;

    if (dictionary == NULL)
    {
        printf("Invalid argument.\n");
        return false;
    }
    
    if (dictionary != NULL)
    {
        isloaded = true;
    }
    
    char word[LENGTH];
    count = 0;
    
    int hash_value; //declare hash value variable
    node *tmp = NULL; //declare temperary pointer
    node *head = NULL; // declare head pointer
    

    while (fscanf(dict_file, "%s", word) != EOF)
    {
        //TODO
        node *n = malloc(sizeof(node));
        
        if(n == NULL)
        {
            printf("Failed to load");
            return 1;
        }
        
        if(isloaded == true)
        {
            count++;
        }
        
        hash_value = hash(word);
        
        
        //head = table[hash_value];
        //tmp = head;
        
        strcpy(n->word, word);
        //n->next = NULL;
        n = n->next;
        
        for (node *temp = table[hash_value]; temp != NULL; temp = temp->next)
            {
                node *temp2 = temp->next;

                if (temp2 == NULL)
                {
                    for (int k = 0; k < strlen(word); k++)
                    {
                        n->word[k] = word[k];
                    }
                temp->next = n;

                n->next = NULL;
                }
            }
    

    while(tmp != NULL)
    {
        free(tmp->word);
        tmp = tmp->next->next;
    }
    
    if (tmp == NULL)
    {
        unload();
    }
}
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return true;
}
