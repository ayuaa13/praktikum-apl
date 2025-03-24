#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#define MAX_USER 10
#define MAX_PRODUK 100

// Struct data pengguna
struct User {
    string nama;
    string nim;
};

// Struct data produk daging
struct Produk {
    string nama;
    int stok;
    int harga;
};

// Nested user dan produk
struct Database {
    User users[MAX_USER];
    int jumlahUser = 0;
    Produk produk[MAX_PRODUK];
    int jumlahProduk = 0;
};

int main() {
    Database db;
    string nama, nim;
    int kesempatan = 3;
    int pilihan;

    cout << "===== PROGRAM MANAJEMEN PENJUALAN DAGING =====\n";

    if (db.jumlahUser < MAX_USER) {
        cout << "Silakan lakukan registrasi.\n";
        cout << "Masukkan Nama: ";
        getline(cin, db.users[db.jumlahUser].nama);
        cout << "Masukkan Password: ";
        cin >> db.users[db.jumlahUser].nim;
        db.jumlahUser++;
        cout << "Registrasi berhasil! silahkan login.\n";
    }

    bool loginBerhasil = false;
    while (kesempatan > 0 && !loginBerhasil) {
        cout << "Masukkan Nama: ";
        cin.ignore();
        getline(cin, nama);
        cout << "Masukkan NIM: ";
        cin >> nim;

        for (int i = 0; i < db.jumlahUser; i++) {
            if (db.users[i].nama == nama && db.users[i].nim == nim) {
                loginBerhasil = true;
                cout << "Login berhasil!\n";
                break;
            }
        }

        if (!loginBerhasil) {
            kesempatan--;
            cout << "Login gagal! " << kesempatan << endl;
        }
    }

    if (!loginBerhasil) {
        cout << "Anda gagal login 3 kali. Program berhenti.\n";
        return 0;
    }

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Tampilkan Produk\n";
        cout << "2. Tambah Produk\n";
        cout << "3. Ubah Produk\n";
        cout << "4. Hapus Produk\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (db.jumlahProduk == 0) {
                cout << "Tidak ada produk dalam daftar.\n";
            } else {
                cout << "\n===== DAFTAR PRODUK =====\n";
                cout << "+----+---------------+------+----------+\n";
                cout << "| No | Nama Produk   | Stok | Harga/Kg |\n";
                cout << "+----+---------------+------+----------+\n";
                for (int i = 0; i < db.jumlahProduk; i++) {
                    cout << "| " << setw(2) << i + 1 << " | " << setw(13) << db.produk[i].nama
                         << " | " << setw(4) << db.produk[i].stok
                         << " | " << setw(8) << db.produk[i].harga << " |\n";
                }
                cout << "+----+---------------+------+----------+\n";
            }
        } else if (pilihan == 2) {
            if (db.jumlahProduk < MAX_PRODUK) {
                cout << "Masukkan Nama Produk: ";
                cin.ignore();
                getline(cin, db.produk[db.jumlahProduk].nama);
                cout << "Masukkan Stok Produk: ";
                cin >> db.produk[db.jumlahProduk].stok;
                cout << "Masukkan Harga per Kg: ";
                cin >> db.produk[db.jumlahProduk].harga;

                db.jumlahProduk++;
                cout << "Produk berhasil ditambahkan!\n";
            } else {
                cout << "Kapasitas penuh!\n";
            }
        } else if (pilihan == 3) {
            int index;
            cout << "Masukkan nomor produk yang ingin diubah: ";
            cin >> index;

            if (index < 1 || index > db.jumlahProduk) {
                cout << "Nomor produk tidak valid!\n";
            } else {
                cout << "Masukkan Nama Baru: ";
                cin.ignore();
                getline(cin, db.produk[index - 1].nama);
                cout << "Masukkan Stok Baru: ";
                cin >> db.produk[index - 1].stok;
                cout << "Masukkan Harga Baru: ";
                cin >> db.produk[index - 1].harga;
                cout << "Produk berhasil diubah!\n";
            }
        } else if (pilihan == 4) {
            int index;
            cout << "Masukkan nomor produk yang ingin dihapus: ";
            cin >> index;

            if (index < 1 || index > db.jumlahProduk) {
                cout << "Nomor produk tidak valid!\n";
            } else {
                for (int i = index - 1; i < db.jumlahProduk - 1; i++) {
                    db.produk[i] = db.produk[i + 1];
                }
                db.jumlahProduk--;
                cout << "Produk berhasil dihapus!\n";
            }
        } else if (pilihan == 5) {
            cout << "Terima kasih telah menggunakan program ini!\n";
        } else {
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}