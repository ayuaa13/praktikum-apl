// //1
// #include <iostream>
// using namespace std;

// // Fungsi untuk menukar nilai menggunakan pointer
// void tukar(int *a, int *b) {
//     int temp = *a;
//     *a = *b;
//     *b = temp;
// }

// int main() {
//     int x, y;

//     // Input nilai awal
//     cout << "Masukkan nilai pertama (x): ";
//     cin >> x;
//     cout << "Masukkan nilai kedua (y): ";
//     cin >> y;

//     // Tampilkan nilai sebelum penukaran
//     cout << "\nSebelum penukaran:" << endl;
//     cout << "x = " << x << ", y = " << y << endl;

//     // Tukar nilai menggunakan pointer
//     tukar(&x, &y);

//     // Tampilkan nilai setelah penukaran
//     cout << "\nSetelah penukaran:" << endl;
//     cout << "x = " << x << ", y = " << y << endl;

//     return 0;
// }


//2
#include <iostream>
using namespace std;

int main() {
    char str[100]; // Menyediakan buffer untuk input string
    cout << "Masukkan sebuah string: ";
    cin.getline(str, 100); // Membaca input dari pengguna

    // Pointer ke awal string
    char* ptr = str;

    int panjang = 0;

    // Iterasi sampai karakter null-terminator ('\0') ditemukan
    while (*ptr != '\0') {
        panjang++;
        ptr++; // Geser pointer ke karakter berikutnya
    }

    cout << "Panjang string adalah: " << panjang << endl;

    return 0;
}
