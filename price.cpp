#include "price.h"
#include <iostream>
#include <cstdio>

using namespace std;

// ПРОТОТИПИ ФУНКЦІЙ
short int round(short int kop);
money add(money moloco, money hlib);
money multiply(money price, int count);
void processAll(const char* filename, int quantity);

int main() {
    FILE* file = fopen("prices.txt", "r");
    if (file == NULL) {
        cout << "Unable to open file\n";
        return 1;
    }
    
    // вивід файлу в термінал
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    
    // повернути на початок файлу
    rewind(file);
    
    // тотальна структура грошей
    money total = {0, 0};
    money temp;
    
    // ТИМЧАСОВІ ЗМІННІ ТИПУ int ДЛЯ ЧИТАННЯ
    int grn, kop;
    
    // читання та присвоєння грошей з файлу
    while (fscanf(file, "%d %d", &grn, &kop) == 2) {
        // перевірка на мінусову ціну
        if (grn < 0 || kop < 0) {
            cout << "Error: Negative price found!\n";
            continue;
        }
        temp.grn = (short)grn;
        temp.kop = (short)kop;
        total = add(total, temp);
    }
    
    fclose(file);
    
    cout << "Total: " << total.grn << " grn " << total.kop << " kop\n";
    
    return 0;
}

short int round(short int kop){
    short int rounded_kop = kop % 10;
    short int result;
    
    if(rounded_kop < 5) 
        result = kop - rounded_kop;
    else 
        result = kop + (10 - rounded_kop);
    
    return result;
}

money add(money moloco, money hlib){
    money syr; 

    syr.grn = moloco.grn + hlib.grn;
    syr.kop = moloco.kop + hlib.kop;

    if (syr.kop >= 100) {
        syr.grn += syr.kop / 100;
        syr.kop = syr.kop % 100;
    }
    syr.kop = round(syr.kop);

    return syr;
}

money multiply(money price, int count) {
    money result;
    result.grn = price.grn * count;
    result.kop = price.kop * count;
    
    if (result.kop >= 100) {
        result.grn += result.kop / 100;
        result.kop = result.kop % 100;
    }
    result.kop = round(result.kop);
    
    return result;
}

void processAll(const char* filename, int quantity) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        cout << "Cannot open file\n";
        return;
    }
    
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    rewind(file);
    
    money total = {0, 0};
    money item;
    
    // ТИМЧАСОВІ ЗМІННІ ТИПУ int ДЛЯ ЧИТАННЯ
    int grn, kop;
    
    while (fscanf(file, "%d %d", &grn, &kop) == 2) {
        if (grn < 0 || kop < 0) {
            cout << "Negative price skipped\n";
            continue;
        }
        item.grn = (short)grn;
        item.kop = (short)kop;
        money multiplied = multiply(item, quantity);
        total = add(total, multiplied);
    }
    
    fclose(file);
    
    cout << "\nResult: " << total.grn << " grn " << total.kop << " kop\n";
}