#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include"valuation.h"
#define InterestRate 1.05


double valuation(double* EPS, double AvGrowth, double ForeverGrowth, double WACC, double StockPrice, double PBR) {
    double value;
    double growthrate;
    double SumofEPS = 0;
    growthrate = (pow(EPS[2] / EPS[0] - 1, 0.5) + AvGrowth) / 2;
    for (int i = 0; i < 3; i++) {
        SumofEPS += EPS[i] / pow(InterestRate, i);
    }
    for (int i = 3; i < 7; i++) {
        SumofEPS += EPS[2] * pow(1 + growthrate / 100, i - 2) / pow(InterestRate, i);
    }
    //calculate SumofEPS
    double TerminalValue;
    TerminalValue = EPS[2] * (1 + ForeverGrowth / 100) / (WACC / 100 - ForeverGrowth / 100);
    //calculate TerminalValue
    double BookValue;
    BookValue = StockPrice / PBR;
    //calculate BookValue
    value = SumofEPS + TerminalValue + BookValue;
    // calculate valuation of Stock
    return value;
}