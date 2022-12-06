// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Respresents a node in a trie
typedef struct trie
{
    bool is_word;
    struct nod* letters[27];
}
nod;
nod *root;

int counter = 0;                       // counter to determine size of dictionary




// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];    // an array of node pointers to the beginning of each linked list

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO  4  use strcmp and tolower      while (word != NULL , if strcomp tolower == true, return true, else word = word ->next)
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // 2 TODO: Improve this hash function
    return toupper(word[0]) - 'A'; // sorts words by first letter; sort by 3 first letters?
    
}

//  1 Loads dictionary into memory, returning true if successful, else false             
bool load(const char *dictionary)
{
    // TODO : file I/O, node* new_node = malloc(node), fscanf(file, "%s",new_node ->word),hash word
    
    if fopen(dictionary) == NULL                                     //open dictionary, if file pointer returned by fopen function is void
    {
        printf("Unable to open dictionary");                            // print error message and return false
        return false;
    }
    else                                                                // if fopen returned valid file pointer
    {                 
    
    while fscanf(dictionary) !=EOF                                          // until the end of dictionary file : if fscanf returns EOF, end is reached

    {

    fscanf(dictionary,"%s", word) ;                                   // reads one string at a time
    counter ++;                                                       // increment word count for SIZE function
    return true;                                                      // return true
    }

    /***********************Hash Table*******************************************************************/
    node *new_node = malloc(sizeof(node));                            // create new node for word
    if   *new_node == NULL                                           // check if return is null
    {
        printf("memory error");
        unload();        
        return false;
    }
    strcpy(word, new_node->word);                                     // copy word into node, initialize value field
    new_node -> next = NULL;                                          // initialize next field, theorhetically, last item in ll
    int i = 0;

    
    i = hash(word);                                                // hash word 
     
    /* new_node->next = table[i];                                     // new_node points to first element in list
    /* table[i] = new_node;                                           // new_node is first element */

    node *cursor = table[i];                            // to insert new element at the end of linked list
    while (cursor != NULL)                              // traverse linked list until pointer ( table[i] or pointer element in node) points to NULL, hence, end of the list
    {
        cursor = cursor->next                           // point to next element
    }   
    if cursor == NULL
    {
        cursor->next = new_node;                        // have last item point to new_node which becomes new last item
    }
    }

    return true;

    }

}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO  3                                              // for /while load counter++
    if load(dictionary) == true
    {
        return count;
    }
    else
    {
    return 0;
    }
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO       5                             //    free liked list by traversing
    return false;
}


/*ADDITIONAL SOURCES I used : 
https://www.youtube.com/playlist?list=PLpPXw4zFa0uKKhaSz87IowJnOTzh9tiBk    
https://www.youtube.com/watch?v=2Ti5yvumFTU&t=541s&ab_channel=JacobSorber
https://www.youtube.com/watch?v=3CbFFVHQrk4&t=577s


*/