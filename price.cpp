#include "price.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string line;
    ifstream file("lab1.cpp");
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << '\n';
        }
        file.close();
    } else {
        cout << "Unable to open file\n";
    }
    return 0;
}
// 46
short int round(short int kop){
    short int rounded_kop = kop % 10; // 6
    int ost1 = 10 - rounded_kop; // 4
    int ost2 = 5 - rounded_kop; // -1
    if(rounded_kop < 5 ) kop += ost2;
    if(rounded_kop >= 5) kop += ost1;
    return kop;
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
