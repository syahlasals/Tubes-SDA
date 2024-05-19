/* File        : header.h 									    */  
/* Deskripsi   : Header file untuk ADT Non Binary Tree Warisan	*/ 
/* Dibuat oleh : Agra Anisa Ibtisamah		231511067
				 Elsa Monika Sinaga     	231511074
				 Syahla Salsabila			231511095 		    */
/* Tanggal     : 14-05-2024 								    */ 

#ifndef header_h
#define header_h

#include <stdlib.h>
#include <stdbool.h>

typedef struct TPerson *Person;
typedef struct TPerson {
    char *nama;
    float warisan;
    bool status;
    Person next;
    Person first_child;
} TPerson;

typedef struct{
    Person root;
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
