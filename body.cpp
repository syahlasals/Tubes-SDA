#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void createEmptyTree(Root *family)
{
    family->root = NULL;
}

bool isEmpty(Person person)
{
    return person == NULL;
}

bool isRoot(Root family, Person person)
{
    return family.root == person;
}

void insertAyah(Root *family, char *nama, float warisan, bool status)
{
    Person newPerson = (Person)malloc(sizeof(TPerson));
    if (newPerson != NULL)
    {
        newPerson->nama = (char *)malloc(strlen(nama) + 1);
        if (newPerson->nama != NULL)
        {
            strcpy(newPerson->nama, nama);
            newPerson->warisan = warisan;
            newPerson->next = NULL;
            newPerson->status = status;
            newPerson->first_child = NULL;

            if (isEmpty(family->root))
            {
                family->root = newPerson;
                printf("\tData Ayah/Suami berhasil dimasukkan!\n");
            }
            else
            {
                printf("\tError: Root (ayah) sudah ada.\n");
                free(newPerson->nama);
                free(newPerson);
            }
        }
        else
        {
            printf("\tError: Alokasi memori untuk nama gagal.\n");
            free(newPerson);
        }
    }
    else
    {
        printf("\tError: Alokasi memori gagal.\n");
    }
}

void insertIstri(Root *family, char *nama, char *namaSuami, bool status)
{
    Person suami = searchNode(family, namaSuami);
    if (suami != NULL)
    {
        Person newPerson = (Person)malloc(sizeof(TPerson));
        if (newPerson != NULL)
        {
            newPerson->nama = (char *)malloc(strlen(nama) + 1);
            if (newPerson->nama != NULL)
            {
                strcpy(newPerson->nama, nama);
                newPerson->warisan = 0.0;
                newPerson->status = status;
                newPerson->next = NULL;
                newPerson->first_child = NULL;

                if (suami->first_child == NULL)
                {
                    suami->first_child = newPerson;
                    printf("\tIstri berhasil disambungkan dengan status 0 menjadi first child dari node suami.\n");
                }
                else
                {
                    printf("\tSuami sudah memiliki istri.\n");
                    free(newPerson->nama);
                    free(newPerson);
                }
            }
            else
            {
                printf("\tError: Alokasi memori untuk nama gagal.\n");
                free(newPerson);
            }
        }
        else
        {
            printf("\tError: Alokasi memori gagal.\n");
        }
    }
    else
    {
        printf("\tSuami tidak ditemukan.\n");
    }
}

void insertAnak(Root *family, char *nama, char *namaAyah)
{
    Person ayah = searchNode(family, namaAyah);
    if (ayah != NULL)
    {
        Person anak = (Person)malloc(sizeof(TPerson));
        if (anak != NULL)
        {
            anak->nama = (char *)malloc(strlen(nama) + 1);
            if (anak->nama != NULL)
            {
                strcpy(anak->nama, nama);
                anak->warisan = 0.0;
                anak->status = true;
                anak->next = NULL;
                anak->first_child = NULL;

                if (ayah->first_child != NULL)
                {
                    Person istri = ayah->first_child;
                    while (istri->next != NULL)
                    {
                        istri = istri->next;
                    }
                    istri->next = anak;
                    printf("\tAnak berhasil ditambahkan sebagai anak dari istri ayah.\n");
                }
                else
                {
                    printf("\tError: Ayah belum memiliki istri.\n");
                    free(anak->nama);
                    free(anak);
                }
            }
            else
            {
                printf("\tError: Alokasi memori untuk nama anak gagal.\n");
                free(anak);
            }
        }
        else
        {
            printf("\tError: Alokasi memori gagal untuk anak.\n");
        }
    }
    else
    {
        printf("\tError: Ayah tidak ditemukan.\n");
    }
}

Person searchNode(Root *family, char *nama)
{
    Person current = family->root;
    while (current != NULL)
    {
        if (strcmp(current->nama, nama) == 0)
        {
            return current;
        }
        current = current->next;
    }
    printf("\tError: Data tidak ditemukan.\n");
    return NULL;
}

void displayDetailNode(Root *family, Person person)
{
    if (person != NULL)
    {
        if (isRoot(*family, person))
        {
            printf("\tNode ini adalah root.\n");
            printf("\tNama root: %s\n", person->nama);
            printf("\tWarisan root: %.2f\n", person->warisan);
            if (person->first_child != NULL)
            {
                printf("\tIstri root: %s\n", person->first_child->nama);
                printf("\tWarisan istri: %.2f\n", person->first_child->warisan);
                // Tampilkan anak-anak
                printf("\tAnak-anak:\n");
                Person anak = person->first_child->next;
                while (anak != NULL)
                {
                    printf("\t- %s\n", anak->nama);
                    anak = anak->next;
                }
            }
            else
            {
                printf("\tRoot tidak memiliki istri.\n");
            }
        }
        else
        {
            printf("\tNode bukan root.\n");
            printf("\tNama: %s, Warisan: %.2f\n", person->nama, person->warisan);
        }
    }
    else
    {
        printf("\tNode tidak valid.\n");
    }
}
