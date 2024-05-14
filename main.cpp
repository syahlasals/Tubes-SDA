#include <iostream>
#include <string>
using namespace std;

// Fungsi untuk mengubah warna teks
void setColor(int color) {
    cout << "\033[" << color << "m";
}

// Fungsi untuk mengatur tampilan menu
void displayMenu() {
    setColor(36); // Cyan
    cout << "=========================================" << endl;
    setColor(32); // Green
    cout << "        Selamat Datang di FamRoots!" << endl;
    setColor(36); // Cyan
    cout << "=========================================" << endl;
    setColor(0); // Reset
    cout << "Silakan pilih opsi berikut:" << endl;
    setColor(36); // Cyan
    cout << "-----------------------------------------" << endl;
    setColor(33); // Yellow
    cout << "1. Tambahkan Ayah" << endl;
    cout << "2. Tambahkan Ibu" << endl;
    cout << "3. Tambahkan Anak" << endl;
    cout << "4. Hapus Data" << endl;
    cout << "5. Tampilkan Jumlah Warisan" << endl;
    cout << "6. Tampilkan Jumlah Anak" << endl;
    cout << "7. Tampilkan Root yang Terbentuk" << endl;
    setColor(36); // Cyan
    cout << "-----------------------------------------" << endl;
    setColor(0); // Reset
}

int main() {
    displayMenu();

    int pilihan;
    setColor(35); // Magenta
    cout << "Masukkan pilihan Anda: ";
    setColor(0); // Reset
    cin >> pilihan;

    // Placeholder untuk penanganan pilihan pengguna
    setColor(32); // Green
    switch (pilihan) {
        case 1:
            cout << "Anda memilih untuk menambahkan ayah." << endl;
            // Implementasi penambahan ayah di sini
            break;
        case 2:
            cout << "Anda memilih untuk menambahkan ibu." << endl;
            // Implementasi penambahan ibu di sini
            break;
        case 3:
            cout << "Anda memilih untuk menambahkan anak." << endl;
            // Implementasi penambahan anak di sini
            break;
        case 4:
            cout << "Anda memilih untuk menghapus data." << endl;
            // Implementasi penghapusan data di sini
            break;
        case 5:
            cout << "Anda memilih untuk menampilkan jumlah warisan." << endl;
            // Implementasi penampilan jumlah warisan di sini
            break;
        case 6:
            cout << "Anda memilih untuk menampilkan jumlah anak." << endl;
            // Implementasi penampilan jumlah anak di sini
            break;
        case 7:
            cout << "Anda memilih untuk menampilkan root yang terbentuk." << endl;
            // Implementasi penampilan root di sini
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
    }
    setColor(0); // Reset
    return 0;
}
