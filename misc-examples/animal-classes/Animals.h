#include <stdio.h>
#include <string.h>

using namespace std;


class Animal {
    protected:
        char * name; 
        char * owners_name;
        char * breed;
        int weight;
    public:
        Animal(char * a_name, char * a_o_name, char * a_breed, int a_weight) {
            name = new char[30];
            owners_name = new char[60];
            breed = new char[30];
            strcpy(name, a_name);
            strcpy(owners_name, a_o_name);
            strcpy(breed, a_breed);
            weight = a_weight;
        }

        ~Animal() {
            delete name;
            delete owners_name;
            delete breed;
        }

        char * getBreed(){
            return(breed);
        }

        char * getName() {
            return(name);
        }

        virtual char *  Speak()=0;
};


class Dog : public Animal {
    protected:
        char * speak_string;
    public:
        Dog(char * a_name, char * a_o_name, char * a_breed, int a_weight) : Animal(a_name, a_o_name, a_breed, a_weight) {
            speak_string = "woof";
        }

        char * Speak() {
            return(speak_string);
        }
};


class Cat : public Animal {
    protected:
        char * speak_string;
    public:
        Cat(char * a_name, char * a_o_name, char * a_breed, int a_weight) : Animal(a_name, a_o_name, a_breed, a_weight) {
            speak_string = "Meow!";
        }

        char * Speak() {
            return(speak_string);
        }
};
