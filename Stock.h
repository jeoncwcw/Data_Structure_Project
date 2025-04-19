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
implementation�� �ƴ϶� ����� skill�鿡 �����ϱ�
code ������ �߿��Ѱ� �ƴ϶� OOP�� Data Sturucture, Algorithm �� ���� ������ ���̴� �Ϳ� �����ϱ�
homogeneous ���� heterogeneous ������ �ٷ�� ���� �� ��� ���α׷���
 */