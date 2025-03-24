#include <iostream>
namespace std;

//cara 1
struct Mahasiswa {
    char nim[10];
    string nama;
    float nilai;
}

struct Mahasiswa mhs;

//cara 2
struct Mahasiswa {
    char nim[10];
    string nama;
    float nilai;
}

Mahasiswa mhs;
mhs.nim = '022';
mhs.nim = 'ayuu';   //element struct
mhs.nilai = 97;

cout << "NIM :" << mhs.nim << endl;
cout << "Nama :" << mhs.nama << endl;            // contoh output struct
cout << "Nilai Akhir :" << mhs.nilai << endl;

// mhs itu variabel baru yang dibuat dari struct Mahasiswa

