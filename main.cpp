/* File        : main.cpp 									    */  
/* Deskripsi   : main file untuk ADT Non Binary Tree Warisan	*/ 
/* Dibuat oleh : Agra Anisa Ibtisamah		231511067
				 Elsa Monika Sinaga     	231511074
				 Syahla Salsabila			231511095 		    */
/* Tanggal     : 14-05-2024 								    */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
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

bool isValidFloat(const char *str) {
    char *endptr;
    strtof(str, &endptr);
    return *endptr == '\0';
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
    printf("\t[1] Tambahkan Ayah\n");
    printf("\t[2] Tambahkan Istri\n");
    printf("\t[3] Tambahkan Anak\n"); // Added option for adding child
    printf("\t[4] Tampilkan Pohon Keluarga\n");
    printf("\t[5] Tampilkan Jumlah Anak\n");
    printf("\t[6] Cari\n");
    printf("\t[7] Hapus Node\n");
    printf("\t[0] Keluar\n\n");
    setColor(36); // Cyan
    printf("-----------------------------------------\n");
    setColor(0); // Reset
}

int main()
{
    displayAturan();
    Root family;
    createEmptyTree(&family);

    char nama[50], namaSuami[50], namaAyah[50], inputWarisan[50], namaNode[50];
    float warisan;

    displayFamroots();

    printf("\n=========================================\n");
    printf("\n\tMasukkan Nama Ayah/Suami: ");
    scanf("%s", nama);
    do {
        printf("\tMasukkan Warisan: Rp. ");
        scanf("%s", inputWarisan);
        if (!isValidFloat(inputWarisan)) {
            printf("\tError: Input warisan harus berupa angka.\n");
        }
    } while (!isValidFloat(inputWarisan));
    warisan = strtof(inputWarisan, NULL);
    insertAyah(&family, nama, warisan, false);
    printf("\n=========================================\n");
    waitForEnter();

    printf("\n=========================================\n");
    printf("\n\tMasukkan Nama Ibu/Istri: ");
    scanf("%s", nama);
    printf("\tMasukkan Nama Suami: ");
    scanf("%s", namaSuami);
    insertIstri(&family, nama, namaSuami, false);
    printf("\n=========================================\n");
    waitForEnter();

    printf("\n=========================================\n");
    printf("\n\tMasukkan Nama Anak: ");
    scanf("%s", nama);
    printf("\tMasukkan Nama Ayah: ");
    scanf("%s", namaAyah);
    insertAnak(&family, nama, namaAyah);
    printf("\n=========================================\n");
    waitForEnter();

    int menu;

    for (;;)
    {
        displayFamroots();
        displayMenu();

        printf("\tMasukkan pilihan : ");
        scanf("%d", &menu);

        system("cls");
        switch (menu) {
            case 1:
                printf("\n\tMasukkan Nama Ayah/Suami: ");
                scanf("%s", nama);
                do {
                    printf("\tMasukkan Warisan: Rp.");
                    scanf("%s", inputWarisan);
                    if (!isValidFloat(inputWarisan)) {
                        printf("\tError: Input warisan harus berupa angka.\n");
                    }
                } while (!isValidFloat(inputWarisan));
                
                warisan = strtof(inputWarisan, NULL);
                insertAyah(&family, nama, warisan, false);
                waitForEnter(); // Menunggu input Enter dari user
                break;
            case 2:
                printf("\tMasukkan Nama Ibu/Istri: ");
                scanf("%s", nama);
                printf("\tMasukkan Nama Suami: ");
                scanf("%s", namaSuami);
                insertIstri(&family, nama, namaSuami, false);
                waitForEnter(); // Menunggu input Enter dari user
                break;
            case 3:
                printf("\tMasukkan Nama Anak: ");
                scanf("%s", nama);
                printf("\tMasukkan Nama Ayah: ");
                scanf("%s", namaAyah);
                insertAnak(&family, nama, namaAyah);
                waitForEnter(); // Menunggu input Enter dari user
                break;
            case 4:
                displayTree(&family);
                waitForEnter(); // Menunggu input Enter dari user
                break;
            case 5: // Case for displaying number of children
                printf("\tMasukkan Nama Ayah: ");
                scanf("%s", namaAyah);
                displayNumberOfChildren(&family, namaAyah);
                waitForEnter(); // Menunggu input Enter dari user
                break;
            case 6:
                printf("\tCari Nama: ");
                scanf("%s", nama);
                searchPerson(&family, nama);
                waitForEnter();
                break;
            case 7:
                if (family.root != NULL){
                printf("\tMasukkan Nama Node yang Ingin Dihapus: ");
                scanf("%s", namaNode);
                deleteNode(&family, namaNode);
                } else {
                    deleteNode(&family,namaNode);
                }
                waitForEnter(); // Menunggu user menekan Enter sebelum kembali ke menu utama
                break;
            case 0:
                freeTree(family.root);
                return 0;
            default:
                printf("\tPilihan tidak valid.\n");
                waitForEnter(); // Menunggu input Enter dari user
                break;
        }
    }
    return 0;
}