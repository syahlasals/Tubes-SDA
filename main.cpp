/* File        : main.cpp 									    */  
/* Deskripsi   : main file untuk ADT Non Binary Tree Warisan	*/ 
/* Dibuat oleh : Agra Anisa Ibtisamah		231511067
				 Elsa Monika Sinaga     	231511074
				 Syahla Salsabila			231511095 		    */
/* Tanggal     : 14-05-2024 								    */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void freeTree(Person person)
{
    if (person != NULL)
    {
        freeTree(person->first_child);
        freeTree(person->next);
        free(person->nama);
        free(person);
    }
}

void setColor(int color)
{
    printf("\033[%dm", color);
}

void displayMenu()
{
    setColor(36); // Cyan
    printf("=========================================\n");
    setColor(32); // Green
    printf("\tSelamat Datang di FamRoots!\n");
    setColor(36); // Cyan
    printf("=========================================\n");
    setColor(0); // Reset
    printf("\tSilakan pilih opsi berikut:\n");
    setColor(36); // Cyan
    printf("-----------------------------------------\n");
    setColor(33); // Yellow
    printf("\n\t[1] Tambahkan Ayah\n");
    printf("\t[2] Tambahkan Ibu/Istri\n");
    printf("\t[3] Tambahkan Anak\n"); // Added option for adding child
    printf("\t[4] Tampilkan Pohon Keluarga\n");
    printf("\t[5] Tampilkan Jumlah Anak\n");
    printf("\t[6] Tampilkan Detail Istri dan Anak\n");
    printf("\t[8] Tampilkan Detail Ayah\n");
    printf("\t[0] Keluar\n\n");
    setColor(36); // Cyan
    printf("-----------------------------------------\n");
    setColor(0); // Reset
}

int main()
{
    Root family;
    createEmptyTree(&family);
    char menu;
    char namaNode[50];

    for (;;)
    {
        displayMenu();

        printf("\tMasukkan pilihan : ");
        scanf(" %c", &menu);

        char nama[50], namaSuami[50], namaAyah[50];
        float warisan;

        switch (menu)
        {
        case '1':
            printf("\n\tMasukkan Nama Ayah/Suami: ");
            scanf("%s", nama);
            printf("\tMasukkan Warisan: ");
            scanf("%f", &warisan);
            insertAyah(&family, nama, warisan, false);
            break;
        case '2':
            printf("\tMasukkan Nama Ibu/Istri: ");
            scanf("%s", nama);
            printf("\tMasukkan Nama Suami: ");
            scanf("%s", namaSuami);
            insertIstri(&family, nama, namaSuami, false);
            break;
        case '3': // Case for adding child
            printf("\tMasukkan Nama Anak: ");
            scanf("%s", nama);
            printf("\tMasukkan Nama Ayah: ");
            scanf("%s", namaAyah);
            insertAnak(&family, nama, namaAyah);
            break;
        case '4': // Case for displaying family tree
            displayTree(&family);
            break;
        case '5': // Case for displaying number of children
            printf("\tMasukkan Nama Ayah: ");
            scanf("%s", namaAyah);
            displayNumberOfChildren(&family, namaAyah);
            break;
        case '6':
            printf("\n\tMasukkan Nama Ayah: ");
            scanf("%s", namaNode);
            // displayNodeDetail(searchNode(&family, namaNode));
            displayNodeDetail(searchNode(family.root, namaNode));
            break;
        case '8':
            printf("\n\tDetail Node Ayah:\n");
            displayDetailNode(&family, family.root);
            break;
        case '0':
            freeTree(family.root);
            return 0;
        default:
            printf("\tPilihan tidak valid.\n");
            break;
        }
    }
    return 0;
}