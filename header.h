/* File        : header.h 									    */  
/* Deskripsi   : Header file untuk ADT Non Binary Tree Warisan	*/ 
/* Dibuat oleh : Agra Anisa Ibtisamah		231511067
				 Elsa Monika Sinaga     	231511074
				 Syahla Salsabila			231511095 		    */
/* Tanggal     : 14-05-2024 								    */ 

#ifndef header_h
#define header_h

#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
// #include <string>
#include "boolean.h"

using namespace std;
// #define data(P)	(P)->data
// #define next(p)	(p)->next 
// #define max 50

// typedef char* infotype;
typedef struct TPerson * Person;
typedef struct TPerson {
    // string nama;
    char* nama;
    float warisan;
    bool status; // true if child, false otherwise
    Person next;
    Person first_child;
} TPerson;

typedef struct{
	Person root;
} Root;

void createEmptyTree(Root *family);
/* Membuat Tree baru yang masih kosong  */
/* I.S : Tree belum terbuat */
/* F.S : Tree sudah terbuat */

bool isEmpty(Person person);
/* Mengecek apakah suatu tree kosong atau tidak */

bool isRoot(Root family, Person person);
/* Mengecek apakah suatu node tersebut adalah root atau bukan */

// bool isRoot(Root family, Person person);
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */

// void insertAyah(Root *family, string nama, float warisan, bool status);
void insertAyah(Root *family, char* nama, float warisan, bool status);
// void insertIstri(Root *family, string nama, string namaSuami, bool status);
void insertIstri(Root *family, char* nama, char* namaSuami, bool status);
void displayDetailNode(Root *family, Person person);
// Person searchNode(Root *family, string nama);
Person searchNode(Root *family, char* nama);

/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */

void deleteNode();
/* Menghapus Node dari suatu Tree */
/* I.S : Node belum terhapus */
/* F.S : Node sudah terhapus */


#endif