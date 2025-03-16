#include <iostream> 
using namespace std;

bool login();
char menu();
bool KonversiMeter();
bool KonversiCenti();
bool KonversiMile();
bool KonversiFoot();

int main() {
    while (true) {
        if (!login()) {
            cout << "anda sudah 3 kali salah , silahkan coba lagi." ;
            return 0 ;
        }
        while (true) {
            cout << "\n===== SELAMAT ANDA BERHASIL LOGIN =====\n";
            char pilihan = menu();
            switch (pilihan) {
                case '1': KonversiMeter(); break;
                case '2' : KonversiCenti(); break;
                case '3' : KonversiMile(); break;
                case '4' : KonversiFoot(); break;
                case '5' : cout << "keluar"; return 0;
                default : cout << "tidak valid" ;
            }
        }
    }
}

bool login() {
    string nama = "ayu";
    int nim = 222;
    string username;
    int password;

    for (int i = 0; i < 3; i++) {
        cout << "\n===== SILAHKAN LOGIN =====\n";
        cout << "Masukkan Username: "; cin >> username;
        cout << "Masukkan Password: "; cin >> password;
        
        if (username == nama && password == nim) {
            return true;
        } else {
            cout << "Salah! Coba lagi.\n";
        }
    }
    return false;
}

char menu() {
    char pilihan;
    cout << " \n===== MENU KONVERSI =====\n";
    cout << "1. meter ke (cm, mile, foot)\n";
    cout << "2. cm ke (m, mile, foot)\n";
    cout << "3. mile ke (m, cm, foot)\n";
    cout << "4. foot ke (m, cm, mile)\n";
    cout << "5. keluar\n";
    cout << "pilih menu :"; 
    cin >> pilihan; 
    return pilihan;
}

bool KonversiMeter() {
    double meter;
    cout << " \n===== KONVERSI METER =====\n";
    cout << "masukkan nilai meter :"; 
    cin >> meter ;
    cout << "hasil centimeter = " << meter * 100 << "cm\n" ;
    cout << "hasil mile = " << meter / 1609 << "mile\n";
    cout << "hasil foot = " << meter * 3.281 << "foot\n" ;
    return true ;
}

bool KonversiCenti() {
    double cm;
    cout << " \n===== KONVERSI CENTIMETER =====\n";
    cout << "masukkan nilai centimeter : "; cin >> cm ;
    cout << "hasil meter = " << cm / 100 << "cm\n" ;
    cout << "hasil mile = " << cm / 160900 << "mile\n";
    cout << "hasil foot = " << cm / 30.48 << "foot\n";
    return true;
}

bool KonversiMile() {
    double mile;
    cout << " \n===== KONVERSI MILE =====\n";
    cout << "masukkan nilai mile :"; cin >> mile;
    cout << "hasil meter = " << mile * 1609.34 << "meter\n";
    cout << "hasil Centi meter = " << mile * 160934.4 << "cm\n";
    cout << "hasil foot = " << mile * 5280 << "foot\n";
    return true;
}

bool KonversiFoot() {
    double ft;
    cout << " \n===== KONVERSI FOOT =====\n";
    cout << "masukkan nilai foot = "; cin >> ft ;
    cout << "hasil meter = " << ft / 3.281 << "meter\n";
    cout << "hasil centimeter = " << ft * 30.48 << "cm\n";
    cout << "hasil mile = " << ft / 5280 << "mile\n";
    return true;
}

    
