#include "Logic.h"
#include <iostream>
#include <fstream>

using namespace std;

void MNNSHT( Tovar &tovar, int &sht)  
{
    tovar.kop = tovar.kop * sht;
    tovar.grn = tovar.grn * sht;
}

void SUMA( Tovar &tovar, short int &total_kop , int &total_grn)
{
    total_grn += tovar.grn;
    total_kop += tovar.kop;   
}

void KOPTOGRN( short int &total_kop , int &total_grn)
{
    while(total_kop >= 100)
    {
        total_kop -= 100;
        total_grn += 1;         
    }
}

void ROUND(short int &total_kop)
{
    int ost = total_kop % 10;
    int b = 10-ost;
    if (ost == 1 || ost == 2 || ost == 3)  total_kop -= ost;   
    if (ost == 4 || ost == 5|| ost == 6 || ost == 7 || ost == 8 || ost == 9) total_kop+=b;
}

void readTovar() {
    FILE *file = fopen("C:\\Cpp-Labs\\Lab_1\\Chek.txt", "r"); // Встановіть власний шлях до файлу Chek.txt

    if (file == NULL) {
        cout << "Ne vdalos otvoryty fail Chek.txt" << endl;
        return ;
    }

    cout << "\n\n=======| vash chek |=======" << endl;
    cout << "---------------------------" << endl;

    Tovar tovar;
    int sht=0;
    char nazva[50];
    short int total_kop = 0;
    int total_grn = 0;

    while (fscanf(file, "%49s %d %hi %d", nazva, &tovar.grn, &tovar.kop, &sht) == 4) {

        if (tovar.grn < 0 || tovar.kop < 0 || sht < 0) {
            cout << "Error :(  Takogo tovara neisnue." << endl;
            cout << "---------------------------" << endl;
            continue;
        }
        cout << nazva << "   " << tovar.grn << "grn  " << tovar.kop << "kop  " << sht << "x" << endl;
        cout << "---------------------------" << endl;

        MNNSHT( tovar, sht);
        SUMA( tovar, total_kop, total_grn);
        KOPTOGRN(total_kop, total_grn);
    }

    fclose(file);

    ROUND(total_kop);
    KOPTOGRN(total_kop, total_grn);

    cout << "Vasha syma: " << total_grn << "grn  " << total_kop << "kop\n\n" << endl;
    
}


