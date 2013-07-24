#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRINGLEN 20


typedef struct node {
    int id;
    char * word;
    void (*wordfunction)(char *);
    node_t *  next;
} node_t;

node_t * allocate_node ( node_t *);
void printword(char *);
void dump_list (node_t *);
void delete_list (node_t *);
void main(void) {


    node_t * CURRENTNODE=NULL;
    node_t * HEAD=NULL;
  

     int i=0;
     int id_array[11]={0,1,2,3,4,5,6,7,8,9,10};
     char *name[11] = {"fee","fi","fo","fum","I","smell","the","blood","of","an","Englishman"};

    
     for (i=0;i<11;i++)  {
         if (HEAD == NULL) {
             CURRENTNODE = allocate_node(HEAD);
             HEAD = CURRENTNODE;
         } else {
             CURRENTNODE = allocate_node(CURRENTNODE);
         }
         CURRENTNODE->id = id_array[i];
         strncpy(CURRENTNODE->word,name[i],strlen(name[i]));
         CURRENTNODE->wordfunction = &printword;
    }

    dump_list(HEAD);
    delete_list(HEAD);

}

node_t  * allocate_node(node_t * current) {
      
      node_t * newnode;
      newnode = (node_t *) malloc(sizeof(node_t));
      newnode->word = (char *) malloc(MAXSTRINGLEN);
       
      if (current == NULL) {
          newnode->next = NULL;
      } else {
          current->next = newnode;
      }
      return(newnode);
}


void dump_list(node_t * snode)  {

    if (snode->next == NULL) {
        printf("id = %d\n",snode->id);
         snode->wordfunction(snode->word);
         return;
    } else {
       dump_list (snode->next); 
       printf("id = %d\n",snode->id);
       snode->wordfunction(snode->word);
    }
}

            
      
void delete_list (struct node * start) {


    struct node * sptr;
    if (start == NULL) {
       return;
    }
    do {
        free(start->word);
        sptr = start->next;
        free(start);
        start = sptr;
    }  while (start != NULL);

}
    

void printword(char * s) {

    printf("The word is %s\n",s);
}
