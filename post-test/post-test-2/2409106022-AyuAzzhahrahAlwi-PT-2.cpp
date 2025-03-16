#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define MAX_DAGING 100
int panjang = 0;
string produk[MAX_DAGING][3];

int tampilkanMenu() {
    int pilihan ;
        cout << "Menu Program" << endl;
        cout << "1. Tampilkan Produk Daging" << endl;
        cout << "2. Tambah Produk Daging" << endl;
        cout << "3. Ubah Produk Daging" << endl;
        cout << "4. Hapus Produk Daging" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        return pilihan;
}
 
int tambahProduk() {
    if (panjang < MAX_DAGING) {
        cout << "Masukkan Nama Produk Daging: ";
        cin.ignore();
        getline(cin, produk[panjang][0]);
        cout << "Masukkan Stok Produk Daging: ";
        cin >> produk[panjang][1];
        cout << "Masukkan Harga 1 kg: ";
        cin >> produk[panjang][2];
        panjang++;
        return 1;
    } else {
        return 0;
    }
}

int tampilkanProduk() {
    if (panjang == 0) {
        cout << "Tidak ada produk dalam daftar.\n";
        return 0;
    }
    cout << "\nDaftar Produk:\n";
    cout << "+----+---------------+------+-------+" << endl;
    cout << "| No | Nama Produk  | Stok | Harga/Kg |" << endl;
    cout << "+----+---------------+------+-------+" << endl;
    for (int i = 0; i < panjang; i++) {
        cout << "| " << setw(2) << i + 1 << " | " << setw(13) << produk[i][0] 
             << " | " << setw(4) << produk[i][1]
             << " | " << setw(5) << produk[i][2] << " |" << endl;
    }
    cout << "+----+---------------+------+-------+" << endl;
    return 1;
}

int ubahProduk() {
    int indeks;
        cout << "Masukkan nomor produk yang ingin diubah: ";
        cin >> indeks;
        if (indeks > 0 && indeks <= panjang) {
            cout << "Masukkan Nama Produk Baru: ";
            cin.ignore();
            getline(cin, produk[indeks - 1][0]);
            cout << "Masukkan Stok Baru: ";
            cin >> produk[indeks - 1][1];
            cout << "Masukkan Harga Baru: ";
            cin >> produk[indeks - 1][2];
            return 1;
        }
        else {
            return 0;
        }
}
int hapusProduk() {
    int indeks;
        cout << "Masukkan nomor produk yang ingin dihapus: ";
        cin >> indeks;
        if (indeks > 0 && indeks <= panjang) {
            for (int i = indeks - 1; i < panjang - 1; i++) {
                produk[i][0] = produk[i + 1][0];
                produk[i][1] = produk[i + 1][1];
                produk[i][2] = produk[i + 1][2];
            }
            panjang--;
            return 1;
        } else {
            return 0;
        }
}

int main() {
    string User, Pass;
    int kesempatan = 0;
    bool login = false;

    while (kesempatan < 3 && !login) {
        cout << "Masukkan Username: ";
        cin >> User;
        cout << "Masukkan Password: ";
        cin >> Pass;

        if (User == "Ayu13" && Pass == "022") {
            login = true;
            cout << "===== LOGIN BERHASIL! =====\n";
        } else {
            cout << "===== Login gagal! Coba lagi. =====\n";
            kesempatan++;
        }
    }
    if (!login) {
        cout << "===== Anda mencoba 3 kali. Program berhenti. ======";
        return 0;
    }
    int pilihan;
    do {
        pilihan = tampilkanMenu();
        switch (pilihan) {
            case 1:
                tampilkanProduk();
                break;
            case 2:
                if (tambahProduk())
                    cout << "Produk Daging berhasil ditambahkan!\n";
                else
                    cout << "Kapasitas penuh!\n";
                break;
            case 3:
                if (ubahProduk())
                    cout << "Produk Daging berhasil diubah!\n";
                else
                    cout << "Nomor produk tidak ada!\n";
                break;
            case 4:
                if (hapusProduk())
                    cout << "Produk Daging berhasil dihapus!\n";
                else
                    cout << "Nomor produk tidak valid!\n";
                break;
            case 5:
                cout << "Terima kasih telah menggunakan program ini!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 5);

    return 0;
}
