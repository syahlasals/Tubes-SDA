/* File        : body.cpp 									    */
/* Deskripsi   : body file untuk ADT Non Binary Tree Warisan	*/
/* Dibuat oleh : Agra Anisa Ibtisamah		231511067
                 Elsa Monika Sinaga     	231511074
                 Syahla Salsabila			231511095 		    */
/* Tanggal     : 14-05-2024 								    */

#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

void displayAturan(){
    system ("cls");
    ifstream aturan ("aturan.txt");

    if (!aturan.is_open()){
        cout << "gagal membuka file\n";
        return;
    }

    string line;
    while (getline(aturan,line)){
        cout <<  "\t" << line << "\n" ;
    }
    aturan.close();
    waitForEnter();
}
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
    if (searchNode(family->root, nama) != NULL)
    {
        printf("\tError: Nama istri '%s' sudah ada dalam pohon keluarga.\n", nama);
        return;
    }

    // Cari node suami dalam pohon
    Person suami = searchNode(family->root, namaSuami);
    if (suami != NULL)
    {
        // Periksa apakah suami adalah root (ayah)
        if (isRoot(*family, suami))
        {
            // Periksa apakah ayah sudah memiliki istri
            if (suami->first_child == NULL)
            {
                // Buat node baru untuk istri
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

                        // Tambahkan istri sebagai first child dari suami
                        suami->first_child = newPerson;
                        printf("\tIstri berhasil disambungkan dengan status 0 menjadi first child dari node ayah/root.\n");
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
                printf("\tSuami (ayah) sudah memiliki istri.\n");
            }
        }
        else
        {
            printf("\tError: Node yang dimaksud bukan ayah/root.\n");
        }
    }
    else
    {
        printf("\tSuami tidak ditemukan.\n");
    }
}

void insertAnak(Root *family, char *nama, char *namaAyah)
{
    if (searchNode(family->root, nama) != NULL)
    {
        printf("\tError: Nama '%s' sudah ada dalam pohon keluarga.\n", nama);
        return;
    }

    Person ayah = searchNode(family->root, namaAyah);
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

Person searchNode(Person person, char *nama)
{
    if(person == NULL){
        return NULL;
    }
    if (strcmp(person->nama, nama) == 0)
    {
        return person;
    }

    Person found = searchNode(person->first_child, nama);
    if(found != NULL)
    {
        return found;
    }

    return searchNode(person->next, nama);
}

void searchPerson(Root *family, char* nama)
{
    Person person = searchNode(family->root, nama);
    if (person != NULL)
    {
        printf("\n\tData Ditemukan!\n");

        if(isRoot(*family, person))
        {
            detailRoot(family, person);
        }
        else{
            detailNode(person);
        }
    }
    else{
        printf("\tData tidak ditemukan!");
    }
}

void detailRoot(Root *family, Person person)
{
    if (person != NULL)
    {
        if (isRoot(*family, person))
        {
            printf("\tNode ini adalah root.\n");
            printf("\tNama: %s\n", person->nama);
            printf("\tWarisan: Rp. %.2f\n", person->warisan);
            printf("\tStatus : %s\n", (person->status ? "Anak" : "Orang tua"));
        }
    }
    else
    {
        printf("\tNode tidak valid.\n");
    }
}

void displayTree(Root *family)
{
    if (isEmpty(family->root))
    {
        printf("Pohon keluarga kosong.\n");
    }
    else
    {
        printf("Tampilan Pohon Keluarga:\n");
        displayTreeNode(family->root, 0);
    }
}

void displayTreeNode(Person person, int depth)
{
    if (person != NULL)
    {
        // Tampilkan informasi node
        for (int i = 0; i < depth; ++i)
        {
            printf("\t");
        }
        printf("- %s (Warisan: Rp. %.2f)\n", person->nama, person->warisan);

        // Tampilkan anak-anak secara rekursif
        if (person->first_child != NULL)
        {
            displayTreeNode(person->first_child, depth + 1);
        }

        // Tampilkan saudara kandung
        if (person->next != NULL)
        {
            displayTreeNode(person->next, depth);
        }
    }
}

int countChildren(Person person)
{
    int count = 0;
    Person child = person->first_child;
    while (child != NULL)
    {
        if (child->status)
        { // Skip the first child if it's an adult
            count++;
        }
        child = child->next;
    }
    return count;
}

void displayNumberOfChildren(Root *family, char *namaAyah)
{
    Person ayah = searchNode(family->root, namaAyah);
    if (ayah != NULL)
    {
        int childrenCount = countChildren(ayah);
        printf("\tJumlah anak dari %s adalah: %d\n", namaAyah, childrenCount);
    }
    else
    {
        printf("\tError: Ayah tidak ditemukan.\n");
    }
}

void detailNode(Person person)
{
    if (person != NULL)
    {
        printf("\tDetail Node:\n");
        printf("\tNama: %s\n", person->nama);
        printf("\tWarisan: Rp. %.2f\n", person->warisan);
        printf("\tStatus : %s\n", (person->status ? "Anak" : "Orang tua"));
    }
    else
    {
        printf("\tNode tidak valid.\n");
    }
}

void waitForEnter() {
    printf("\n\tTekan Enter untuk kembali ke menu utama...");
    getchar(); // Menunggu input enter dari user
    while(getchar() != '\n'); // Membersihkan buffer input
    system("cls");
}

void deleteNode(Root *family, char *nama) {
    // mengecek apakah tree kosong
    if (family->root == NULL) {
        printf("\tError: Pohon keluarga kosong.\n");
        return;
    }

    // Jika root yang akan dihapus
    if (strcmp(family->root->nama, nama) == 0) {
        Person temp = family->root;
        
        if (temp->warisan > 0 && temp->status == false) {
            Person first_child = temp->first_child;
            Person next = (first_child != NULL) ? first_child->next : NULL;

            int jumlahAnak = 0;
            float totalWarisan = temp->warisan;
            float warisanBagian = totalWarisan * 0.05;

            while (first_child!=NULL)
            {
                jumlahAnak++;
                first_child = first_child->next;
            }

            float warisanAnak = (totalWarisan - warisanBagian) / jumlahAnak;
            float warisanAnakAnak = totalWarisan / jumlahAnak;
            float warisanIstri = warisanAnak + warisanBagian;
            
            first_child = temp->first_child;
            // // Transfer warisan ke istri
            if (temp->first_child != NULL && temp->first_child->status == false) {
                temp->first_child->warisan += warisanIstri;
            } else {
                temp->first_child->warisan += warisanAnakAnak;
            }

            next = first_child->next;
            // Transfer warisan ke anak
            while (next != NULL) {
                if (temp->first_child != NULL && temp->first_child->status == false){
                    next->warisan += warisanAnak;
                } else {
                    next->warisan += warisanAnakAnak;
                }
                next = next->next;
            }
        }

        if(temp->first_child != NULL){
            // Menetapkan istri sebagai root baru
            family->root = temp->first_child;
            family->root->first_child = temp->first_child->next;
            temp->first_child->next = NULL;
        } else {
            // jika root tidak memiliki firstchild, tree akan menjadi kosong
            family->root = NULL;
        }

        free(temp->nama);
        free(temp);
        printf("\tRoot berhasil dihapus.\n");
        return;
    } else {
        printf ("\tError : Data tidak ditemukan");
    }

    // Jika bukan root yang dihapus, panggil fungsi helper untuk mencari dan menghapus node
    deleteNodeHelper(&(family->root->first_child), nama);
    deleteNodeHelper(&(family->root->next), nama);
}

void deleteNodeHelper(Person *current, char *nama) {
    if (*current == NULL) {
        return;
    }

    if (strcmp((*current)->nama, nama) == 0) {
        Person temp = *current;
        *current = (*current)->next;
        free(temp->nama);
        free(temp);
        printf("\tNode berhasil dihapus.\n");
    }

    deleteNodeHelper(&(*current)->next, nama);
    deleteNodeHelper(&(*current)->first_child, nama);
}

void displayFamroots(){
    FILE *fp;
    char text[999];

    fp = fopen("Assets/FamRoots-Title.txt", "rt");

    if(fp == NULL){
        printf("\tError: File tidak ditemukan\r\t.");
        exit(1);
    }

    while(fgets(text, sizeof(text), fp) != NULL){
        printf("%s\r", text);
    }
}