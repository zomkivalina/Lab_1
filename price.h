#ifndef PRICE_H
#define PRICE_H

struct money{
int grn;
short int kop;
};

void roundMoney(short int kop, short int *result);
void addMoney(money a, money b, money *result);
void multiplyMoney(money price, int count, money *result);
void processAll(const char* filename, int quantity);
   

#endif     
