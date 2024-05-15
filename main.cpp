#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

void freeTree(Person person) {
    if (person != NULL) {
        freeTree(person->first_child);
        freeTree(person->next);
        free(person->nama);
        free(person);
    }
}

int main()
{
    Root family;
    createEmptyTree(&family);
    char menu;

    for (;;)
    {
        printf("\n\t[1] Tambah Ayah/Suami\n");
        printf("\t[2] Tambah Ibu/Istri\n");
        printf("\t[3] Tampil Detail Ayah\n");
        printf("\t[0] Keluar\n");
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
