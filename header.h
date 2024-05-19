#ifndef header_h
#define header_h

#include <stdlib.h>
#include <stdbool.h>

// Struct for a person in the family tree
typedef struct TPerson *Person;
typedef struct TPerson {
    char *nama;            // Name of the person
    float warisan;         // Inheritance amount
    bool status;           // true if child, false otherwise
    Person next;           // Pointer to the next sibling
    Person first_child;    // Pointer to the first child
} TPerson;

// Struct for the root of the family tree
typedef struct{
    Person root;    // Pointer to the root person
} Root;

void createEmptyTree(Root *family);
bool isEmpty(Person person);
bool isRoot(Root family, Person person);
void insertAyah(Root *family, char *nama, float warisan, bool status);
void insertIstri(Root *family, char *nama, char *namaSuami, bool status);
void insertAnak(Root *family, char *nama, char *namaAyah);
void displayDetailNode(Root *family, Person person);
Person searchNode(Root *family, char *nama);
void deleteNode();
void displayTreeNode(Person person, int depth);
void displayTree(Root *family);
void displayNumberOfChildren(Root *family, char *namaAyah);
void displayNodeDetail(Person person);

#endif
