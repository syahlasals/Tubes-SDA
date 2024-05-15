#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include "header.h"

using namespace std;

void freeTree(Person person) {
    if (person != NULL) {
        freeTree(person->first_child);
        freeTree(person->next);
        free(person->nama);
        free(person);
    }
}

// Fungsi untuk mengubah warna teks
void setColor(int color) {
    cout << "\033[" << color << "m";
}

// Fungsi untuk mengatur tampilan menu
void displayMenu() {
    setColor(36); // Cyan
    cout << "=========================================" << endl;
    setColor(32); // Green
    cout << "\tSelamat Datang di FamRoots!" << endl;
    setColor(36); // Cyan
    cout << "=========================================" << endl;
    setColor(0); // Reset
    cout << "\tSilakan pilih opsi berikut:" << endl;
    setColor(36); // Cyan
    cout << "-----------------------------------------" << endl;
    setColor(33); // Yellow
    printf("\n\t[1] Tambahkan Ayah");
    printf("\n\t[2] Tambahkan Ibu/Istri");
    printf("\n\t[3] Tambahkan Anak");
    printf("\n\t[4] Hapus Data");
    printf("\n\t[5] Tampilkan Jumlah Warisan");
    printf("\n\t[6] Tampilkan Jumlah Anak");
    printf("\n\t[7] Tampilkan Tampilkan Root yang Terbentuk");
    printf("\n\t[0] Keluar\n");
    setColor(36); // Cyan
    cout << "-----------------------------------------" << endl;
    setColor(0); // Reset
}

int main()
{
    Root family;
    createEmptyTree(&family);
    char menu;

    for (;;)
    {
        displayMenu();

        printf("\tMasukkan pilihan : ");
        scanf(" %c", &menu); // Baca karakter menu, spasi sebelum %c untuk mengabaikan newline sebelumnya

        char nama[50], namaSuami[50];
        float warisan;

        switch (menu)
        {
        case '1':
            printf("\tMasukkan Nama Ayah/Suami: ");
            scanf("%s", nama); // Baca nama Ayah/Suami
            printf("\tMasukkan Warisan: ");
            scanf("%f", &warisan); // Baca warisan
            insertAyah(&family, nama, warisan, false);
            break;
        case '2':
            printf("\tMasukkan Nama Ibu/Istri: ");
            scanf("%s", nama); // Baca nama Ibu/Istri
            printf("\tMasukkan Nama Suami: ");
            scanf("%s", namaSuami); // Baca nama Suami
            insertIstri(&family, nama, namaSuami, false); // false menunjukkan bahwa istri bukanlah seorang anak
            break;
        case '3':
            printf("\tDetail Node Ayah:\n");
            displayDetailNode(&family, family.root);
            break;
        case '0':
            freeTree(family.root);
            return 0;
        default:
            printf("\tPilihan tidak valid.\n");
            break;
        }

        // Bersihkan newline di input buffer
        while (getchar() != '\n');
    }
    return 0;
}
