#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h"

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
    // alokasi memori
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
                printf("Data Ayah/Suami berhasil dimasukkan!\n");
            }
            else
            {
                printf("Error: Root (ayah) sudah ada.\n");
                free(newPerson->nama); // free node
                free(newPerson);       // free node
            }
        }
        else
        {
            printf("Error: Alokasi memori untuk nama gagal.\n");
            free(newPerson); // free node
        }
    }
    else
    {
        printf("Error: Alokasi memori gagal.\n");
    }
}

void insertIstri(Root *family, char *nama, char *namaSuami, bool status)
{
    // searchNode untuk mencari suami
    Person suami = searchNode(family, namaSuami);
    if (suami != NULL)
    {
        // alokasi memori
        Person newPerson = (Person)malloc(sizeof(TPerson));
        if (newPerson != NULL)
        {
            newPerson->nama = (char *)malloc(strlen(nama) + 1);
            if (newPerson->nama != NULL)
            {
                strcpy(newPerson->nama, nama);
                newPerson->warisan = 0.0; // default 0.0 untuk istri
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
                    free(newPerson->nama); // free node
                    free(newPerson);       // free node
                }
            }
            else
            {
                printf("\tError: Alokasi memori untuk nama gagal.\n");
                free(newPerson); // free node
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

Person searchNode(Root *family, char *nama)
{
    Person current = family->root;
    while (current != NULL)
    {
        if (strcmp(current->nama, nama) == 0)
        {
            return current; // Node found
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
