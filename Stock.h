#pragma once
#ifndef STOCK_H
#define STOCK_H
#define InterestRate = 0.05;

class Stock {
private:
    Stock* next;
protected:
    char* Ticker;
    double EPS[3];
    double PBR;
    const double StockPrice;
    double value;
    const double WACC;
    double ForeverGrowth;
    static int numofStock;
    double valueratio;
public:
    Stock(char*, double, double ,double, double*);
    virtual ~Stock();
    virtual void PrintStock() = 0;
    virtual void Valuation() = 0;
    Stock* getNext();
    double getValueRatio();
    void setNext(Stock*);
};
#endif


/*
implementation이 아니라 적용된 skill들에 집중하기
code 내용이 중요한게 아니라 OOP나 Data Sturucture, Algorithm 에 대한 지식을 보이는 것에 집중하기
homogeneous 보다 heterogeneous 내용을 다루는 것이 더 고급 프로그래밍
 */