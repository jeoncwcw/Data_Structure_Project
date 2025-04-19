#define _CRT_SECURE_NO_WARNINGS
#include "Stock.h"
#include <iostream>
#include <cstring>
using namespace std;

int Stock::numofStock = 0;

Stock::Stock(char* Ticker, double PBR, double StockPrice, double WACC, double* EPS):StockPrice(StockPrice), WACC(WACC) {
    numofStock++;
    this->Ticker = new char[strlen(Ticker) + 1];
    strcpy(this->Ticker, Ticker);
    this->PBR = PBR;
    for (int i = 0; i < 3; i++) {
        this->EPS[i] = EPS[i];
    }
    next = NULL;
    ForeverGrowth = 0;
    value = 0;
    valueratio = 0;
}

Stock::~Stock() {
    delete[] Ticker;
}

Stock* Stock::getNext() {
    return next;
}

void Stock::setNext(Stock* next) {
    this->next = next;
}

double Stock::getValueRatio() {
    return valueratio;
}