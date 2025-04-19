#include <iostream>
using namespace std;

// int main()
// {
//     // declare variables
//     int var1 = 3;
//     int var2 = 24;
//     int var3 = 17;

//     // print address of var1
//     cout << "Address of var1: "<< &var1 << endl;

//     // print address of var2
//     cout << "Address of var2: " << &var2 << endl;

//     // print address of var3
//     cout << "Address of var3: " << &var3 << endl;
// }




// #include <stdio.h>

// int main(){
//     int score = 50;
//     int hp = 100;

//     // membuat pointer dengan isi alamat memori dari hp
//     int *ptr_hp = &hp;

//     // print isi variabel dan alama memori
//     printf("Nama Variabel \t Alamat \t Konten\n");
//     printf("score \t\t %x \t %d \n", &score, score);
//     printf("hp \t\t %x \t %d \n", &hp, hp);
//     printf("ptr_hp \t\t %x \t %x \n", &ptr_hp, ptr_hp);
//     printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);

//     // mengubah data pada alamat memori dengan pointer
//     *ptr_hp = 95;

//     printf("hp \t\t %x \t %d \n", &hp, hp);
//     printf("*ptr_hp \t %x \t %d \n", &ptr_hp, *ptr_hp);

//     return 0;
// }





int main(){
    struct Weapon {
        string name;
        int attack;
        int guard;
    };

    struct Player {
        string name;
        int score;
        int hp;
        Weapon *weapon;
    };

    Player player1;
    player1.name    = "Petani Kode";
    player1.score   = 0;
    player1.hp      = 100;
    player1.weapon = new Weapon;

    (*player1.weapon).name = "Katana";
    (*player1.weapon).attack = 16;
    (*player1.weapon).guard = 10;

    // cetak status player
    cout << "PLAYER STATUS" << endl;
    cout << "Name: " << player1.name << endl;
    cout << "Score: " << player1.score << endl;
    cout << "HP: " << player1.hp << endl;
    cout << "Weapon" << endl;
    cout << "  name: " << (*player1.weapon).name << endl;
    cout << "  attack: " << (*player1.weapon).attack << endl;
    cout << "  guard: " << (*player1.weapon).guard << endl;

    return 0;
}