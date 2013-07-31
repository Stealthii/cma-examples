#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <errno.h>
#include "Animals.h"

using namespace std;


/* Appends the src char array to the dest char array */
char *
mystrcat(char *dest, const char *src) {
    size_t i,j;
    for (i=0; dest[i] != '\0'; i++);
    for (j=0; src[j] != '\0'; j++)
        dest[i+j] = src[j];
    dest[i+j] = '\0'; // Let's set the trailing char as null
    return dest;
}

int main() {
    vector<Animal *> animal_list;
    FILE * fp;
    char filename[] = "animals.dat";
    char outbuf[255];
    char animalType [40];
    char animalName [50];
    char ownerName [50];
    char ownerName2 [50];
    char animalBreed [50];
    int animalWeight, i;

    if ((fp = fopen(filename, "r")) == NULL) {
        perror("ERROR: Unable to open file!");
        return(1);
    }

    while ((fgets(outbuf,sizeof(outbuf),fp))) {
        sscanf(outbuf,"%s %s %s %s %s %d",animalType,animalName,ownerName,ownerName2,animalBreed,&animalWeight);
        mystrcat(ownerName,ownerName2);
        if (strcmp(animalType,"Cat")) {
            animal_list.push_back(new Cat(animalName,ownerName,animalBreed,animalWeight));
        } else if (strcmp(animalType,"Dog")) {
            animal_list.push_back(new Dog(animalName,ownerName,animalBreed,animalWeight));
        } else {
            continue;
        }
    }

    for (i=0;i<animal_list.size(); i++) {
        cout <<animal_list[i]->getName() << " the " <<animal_list[i]->getBreed() << " says " << animal_list[i]->Speak() << endl;
    }
    fclose(fp);
    return 0;
}
