/*  Program that shows how to take data from a file and put it into a structure */

#include <stdio.h> 
#include <stdlib.h>


#define MAXSIZE 1024

// Define the personnel record
typedef struct personnel_record {
    int id;
    char * fname;
    char * lname;
    float salary;
}precord;

// Note that these two variables are global since they are declared outside of main 
int p_record_index=0;
precord parray[255];

int main(void) {

    FILE * fp;
    char buffer[MAXSIZE];

    


// Read the data in and call fill_p_array to insert each buffer 
// string into the personnel record struct

    fp = fopen("mydatafile","r");
    if (fp == NULL) {
        perror("File open error");
        return(1);
    }


    while  ((fgets(buffer,MAXSIZE,fp)) != NULL) {
        if (fill_p_array(buffer) == -1) {       
            return(1);
        }
    }
  
// Print it out and free any malloc'd memory

    print_p_array();
    cleanup();
}


    
int print_p_array(void) {


    int i;
    for (i=0;i<p_record_index;i++) {
        printf("%d %s %s %f\n",parray[i].id,parray[i].fname,parray[i].lname, parray[i].salary);
   }
}


int fill_p_array(char * bufstring)  {
// We're using malloc to allocate memory for the first name and last name rather than using
// static array declarations, just as a different way of doing things

       parray[p_record_index].fname = (char *) malloc(MAXSIZE);
       if ((parray[p_record_index].fname) == NULL) {
           perror("Malloc failure!");
           return(-1);
       }
       parray[p_record_index].lname = (char *) malloc(MAXSIZE);
       if ((parray[p_record_index].lname) == NULL) {
           perror("Malloc failure!");
           return(-1);
       }

// Stick the contents of the data buffer into the structure. Note that we're using an array of structures, so we have to tell the compiler
// which element of the structure array we want.  We're using p_record_index to point to the (latest) last defined element of the array. 

       sscanf(bufstring,"%d %s %s %f",&(parray[p_record_index].id), (parray[p_record_index]).fname,(parray[p_record_index]).lname,&(parray[p_record_index].salary));
       p_record_index++;
}


int cleanup(void){
   int i;

// Always free your malloc's memory!

   for (i=0;i<p_record_index;i++) {
        free(parray[p_record_index].fname);
        free(parray[p_record_index].lname);
    }
}
