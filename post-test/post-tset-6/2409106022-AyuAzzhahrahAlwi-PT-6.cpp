#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> 
using namespace std;

#define MAX_USER 10
#define MAX_PRODUK 100

struct User {
    string nama;
    string nim;
};

struct Produk {
    string nama;
    int stok;
    int harga;
};

User users[MAX_USER];
Produk produk[MAX_PRODUK];
int jumlahUser = 0;
int jumlahProduk = 0;

void registrasi(User* users, int* jumlahUser) {
    cout << "\n===== REGISTRASI USER =====\n";
    if (*jumlahUser < MAX_USER) {
        cout << " Masukkan Nama              : ";
        cin.ignore();
        getline(cin, users[*jumlahUser].nama);
        cout << " Masukkan NIM (sebagai PIN) : ";
        getline(cin, users[*jumlahUser].nim);
        (*jumlahUser)++;
        cout << "\nRegistrasi berhasil! Silakan login untuk melanjutkan.\n";
    } else {
        cout << "\nKuota user sudah penuh! Tidak bisa registrasi lagi.\n";
    }
}

bool login(User* users, int jumlahUser, int kesempatan = 3) {
    if (kesempatan == 0) return false;

    string nama, nim;
    cout << "\n===== LOGIN USER =====\n";
    cout << " Masukkan Nama : ";
    cin.ignore();
    getline(cin, nama);
    cout << " Masukkan NIM  : ";
    getline(cin, nim);

    for (int i = 0; i < jumlahUser; i++) {
        if ((*(users + i)).nama == nama && (*(users + i)).nim == nim) {
            cout << "\nLogin berhasil! Selamat datang, " << nama << ".\n";
            return true;
        }
    }

    cout << "\nLogin gagal! Nama atau NIM salah.\n";
    cout << "Sisa kesempatan: " << kesempatan - 1 << "\n";
    return login(users, jumlahUser, kesempatan - 1);
}

void tampilkan(Produk* produk, int jumlahProduk) {
    if (jumlahProduk == 0) {
        cout << "Belum ada produk.\n";
    } else {
        cout << "\n===== DAFTAR PRODUK =====\n";
        cout << "+----+---------------+------+----------+\n";
        cout << "| No | Nama Produk   | Stok | Harga/Kg |\n";
        cout << "+----+---------------+------+----------+\n";
        for (int i = 0; i < jumlahProduk; i++) {
            cout << "| " << setw(2) << i + 1 << " | " << setw(13) << produk[i].nama
                 << " | " << setw(4) << produk[i].stok
                 << " | " << setw(8) << produk[i].harga << " |\n";
        }
        cout << "+----+---------------+------+----------+\n";
    }
}

void tambahProduk(Produk* produk, int* jumlahProduk) {
    if (*jumlahProduk < MAX_PRODUK) {
        cout << "Masukkan Nama Produk: ";
        cin.ignore();
        getline(cin, produk[*jumlahProduk].nama);
        cout << "Masukkan Stok Produk: ";
        cin >> produk[*jumlahProduk].stok;
        cout << "Masukkan Harga per Kg: ";
        cin >> produk[*jumlahProduk].harga;
        (*jumlahProduk)++;
        cout << "Produk berhasil ditambahkan.\n";
    } else {
        cout << "Kapasitas produk penuh!\n";
    }
}

void ubahProduk(Produk* produk, int jumlahProduk) {
    tampilkan(produk, jumlahProduk);
    int index;
    cout << "Pilih produk yang akan diubah: ";
    cin >> index;
    if (index < 1 || index > jumlahProduk) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    cout << "Masukkan Nama Baru: ";
    cin.ignore();
    getline(cin, (*(produk + index - 1)).nama);
    cout << "Masukkan Stok Baru: ";
    cin >> (*(produk + index - 1)).stok;
    cout << "Masukkan Harga Baru: ";
    cin >> (*(produk + index - 1)).harga;
    cout << "Produk berhasil diubah!\n";
}

void hapusProduk(Produk* produk, int* jumlahProduk) {
    tampilkan(produk, *jumlahProduk);
    int index;
    cout << "Pilih produk yang akan dihapus: ";
    cin >> index;
    if (index < 1 || index > *jumlahProduk) {
        cout << "Nomor tidak valid!\n";
        return;
    }
    for (int i = index - 1; i < *jumlahProduk - 1; i++) {
        *(produk + i) = *(produk + i + 1);
    }
    (*jumlahProduk)--;
    cout << "Produk berhasil dihapus!\n";
}

void sortNamaAscending(Produk* produk, int jumlahProduk) {
    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {
            if (produk[j].nama > produk[j + 1].nama) {
                swap(produk[j], produk[j + 1]);
            }
        }
    }
    cout << "Produk berhasil diurutkan berdasarkan nama (A-Z).\n";
}

void sortHargaDescending(Produk* produk, int jumlahProduk) {
    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {
            if (produk[j].harga < produk[j + 1].harga) {
                swap(produk[j], produk[j + 1]);
            }
        }
    }
    cout << "Produk berhasil diurutkan berdasarkan harga (terbesar ke terkecil).\n";
}

void bubbleSortStokAscending(Produk* produk, int jumlahProduk) {
    for (int i = 0; i < jumlahProduk - 1; i++) {
        for (int j = 0; j < jumlahProduk - i - 1; j++) {
            if (produk[j].stok > produk[j + 1].stok) {
                swap(produk[j], produk[j + 1]);
            }
        }
    }
    cout << "Produk berhasil diurutkan berdasarkan stok (terkecil ke terbesar) menggunakan Bubble Sort.\n";
}

void menuSorting(Produk* produk, int jumlahProduk) {
    int pilihan;
    do {
        cout << "\n===== MENU SORTING =====\n";
        cout << "1. Urutkan berdasarkan Nama (A-Z)\n";
        cout << "2. Urutkan berdasarkan Harga (Terbesar-Terkecil)\n";
        cout << "3. Urutkan berdasarkan Stok (Terkecil-Terbesar) - Bubble Sort\n";
        cout << "4. Kembali ke Menu Utama\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                sortNamaAscending(produk, jumlahProduk);
                tampilkan(produk, jumlahProduk);
                break;
            case 2:
                sortHargaDescending(produk, jumlahProduk);
                tampilkan(produk, jumlahProduk);
                break;
            case 3:
                bubbleSortStokAscending(produk, jumlahProduk);
                tampilkan(produk, jumlahProduk);
                break;
            case 4:
                cout << "Kembali ke menu utama.\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 4);
}

int main() {
    int pilihan;

    cout << "===== PROGRAM PENJUALAN DAGING =====\n";

    registrasi(users, &jumlahUser);
    if (!login(users, jumlahUser)) {
        cout << "Anda gagal login 3 kali. Program dihentikan.\n";
        return 0;
    }

    do {
        cout << "\n===== MENU UTAMA =====\n";
        cout << "1. Tampilkan Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Sorting Produk\n";
        cout << "6. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: 
                tampilkan(produk, jumlahProduk); 
                break;
            case 2: 
                tambahProduk(produk, &jumlahProduk); 
                break;
            case 3: 
                ubahProduk(produk, jumlahProduk); 
                break;
            case 4: 
                hapusProduk(produk, &jumlahProduk); 
                break;
            case 5:
                menuSorting(produk, jumlahProduk);
                break;
            case 6: 
                cout << "Terima kasih telah menggunakan program!\n"; 
                break;
            default: 
                cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 6);

    return 0;
}