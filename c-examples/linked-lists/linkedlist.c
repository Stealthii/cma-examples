#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRINGLEN 20

struct node * allocate_node (struct node *);
void printoutnames (struct node *);

struct node {
    int id;
    char * word;
    struct node * next; // This is container that points to the linked list,
    struct node * prev; // points next element in list
};

void main(void) {

    // need to initialise nodes, define structure pointers
    struct node * CURRENTNODE = NULL;  //declares pointer to current data structure
    struct node * HEAD = NULL;  // points to start of linked list then every one after that
    struct node * TAIL = NULL;

    //data fed in to linked list - normally comes from file or input
    int i = 0;
    int id_array[10] = {0,1,2,3,4,5,6,7,8,9};
    // need char * as need an array of strings, if just char name would expect list of 11 characters ie. 'a','b' etc
    char *word[11] = {"fee","fi","fo","fum","I","smell","the","blood","of","an","Englishman"};

    // loop to allocate & start link list else keep allocating nodes ITTERATE THROUGH WHOLE ARRAY
    for (i=0;i<11;i++)  {
        if (HEAD == NULL) {
            CURRENTNODE = allocate_node(HEAD); // if 1st time through head always equals null.
            HEAD = CURRENTNODE; // after 1st time through head now points to new node.
        } else {
            // now points to new node after initial 1st node of null.
            CURRENTNODE = allocate_node(CURRENTNODE);
        }
        // set values
        CURRENTNODE->id = id_array[i]; // pointer needs ->
        strncpy(CURRENTNODE->word,word[i],strlen(word[i]));
//      CURRENTNODE->wordfunction = &printword;
    }
    CURRENTNODE = HEAD;
    printoutnames(CURRENTNODE);
}

struct node * allocate_node(struct node * current) {

    struct node * newnode;
    newnode = (struct node *) malloc(sizeof(struct node));
    newnode->word = (char *) malloc(MAXSTRINGLEN);

    // do ifloop to check if current = null, which is 1st time through
    if (current == NULL) {
        newnode->next = NULL;
        newnode->prev = NULL;
    // if not 1st time through allocate next to the newnode
    } else {
    // setting pointer to new node
        current->next = newnode;
        newnode->prev = current;
    }
    return(newnode);
}

// void as not returning a value, same as node above
void printoutnames(struct node * current) { // current

// using while loop to iterate over current pointing to next to next, when it is not equal to 0, ie. when linked list has another element in it, it will prinnt out current word, this will only stop when no further elements in linked list.
    while (current != NULL) {
        printf("The current word is %s\n",current->word);
        current = current->next;
//      if (current->next == NULL) {
//         printf("The current word is %s\n",current->word);
    }
}

