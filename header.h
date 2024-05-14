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
#include <string>
#include "boolean.h"

using namespace std;
#define Nil NULL

// typedef char* infotype;
typedef struct TPerson * Person;
typedef struct TPerson {
    string nama;
    float warisan;
    bool status; // true if child, false otherwise
    Person next;
    Person first_child;
} Person;

typedef struct{
	Person root;
} Root;

void createEmptyTree(Root *root);
/* Membuat Tree baru yang masih kosong  */
/* I.S : Tree belum terbuat */
/* F.S : Tree sudah terbuat */

bool isEmpty(Person *person);
/* Mengecek apakah suatu tree kosong atau tidak */

bool isRoot(Root root, Person person);
/* Mengecek apakah suatu node tersebut adalah root atau bukan */

void insertNode(string nama, bool status);
/* Membuat node dan memasukkan value kedalam node tersebut lalu mengembalikan node tersebut */

Person searchNode(Root X, string nama);
/* Mencari suatu Node berdasarkan subvar nama lalu akan mengembalikan node tersebut jika ketemu */

void deleteNode(Root * X, string nama);
/* Menghapus Node dari suatu Tree */
/* I.S : Node belum terhapus */
/* F.S : Node sudah terhapus */


#endif