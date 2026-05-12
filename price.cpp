#include "price.h"
#include <iostream>
#include <fstream>

using namespace std;

void MNNSHT(Tovar &tovar, int &sht)
{
    int kop = tovar.grn * 100 + tovar.kop;
    kop = kop * sht;

    tovar.grn = kop / 100;
    tovar.kop = kop % 100;
}

void SUMA(Tovar &tovar, int &total_kop , int &total_grn)
{
    total_grn += tovar.grn;
    total_kop += tovar.kop;   
}

void KOPTOGRN(int &total_kop , int &total_grn)
{
    while(total_kop >= 100)
    {
        total_kop -= 100;
        total_grn += 1;         
    }
}

void ROUND(int &total_kop)
{
    int ost = total_kop % 10;

    if (ost >= 5)
        total_kop += (10 - ost);
    else
        total_kop -= ost;
}

void readTovar() {
    FILE *file = fopen("/Users/alinazomkiv/Desktop/Cpp_Labs/Lab_1/prices.txt", "r");

    if (file == NULL) {
        cout << "Ne vdalos otvoryty fail Chek.txt" << endl;
        return ;
    }

    cout << "\n\n=======| vash chek |=======" << endl;
    cout << "---------------------------" << endl;

    Tovar tovar;
    int sht=0;
    char nazva[50];
    int total_kop = 0;
    int total_grn = 0;

    while (fscanf(file, "%49s %d %hi %d", nazva, &tovar.grn, &tovar.kop, &sht) == 4) {

        if (tovar.grn < 0 || tovar.kop < 0 || sht < 0) {
            cout << "Error :(  Takogo tovara neisnue." << endl;
            cout << "---------------------------" << endl;
            continue;
        }

        cout << nazva << "   " << tovar.grn << "grn  " 
             << tovar.kop << "kop  " << sht << "x" << endl;
        cout << "---------------------------" << endl;

        MNNSHT(tovar, sht);
        SUMA(tovar, total_kop, total_grn);
        KOPTOGRN(total_kop, total_grn);
    }

    fclose(file);

    ROUND(total_kop);
    KOPTOGRN(total_kop, total_grn);

    cout << "Vasha syma: " << total_grn << "grn  " 
         << total_kop << "kop\n\n" << endl;
}