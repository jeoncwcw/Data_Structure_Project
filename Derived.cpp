#include"Derived.h"
#include"valuation.h"
#include<iostream>
#include<iomanip>
using namespace std;

/*Define Static Variables*/
const double Technology::AvGrowth = 20.61;
const double Healthcare::AvGrowth = 10.79;
const double Financial_Services::AvGrowth = 11.45;
const double Consumer_Goods::AvGrowth = 10.88;
const double Energy::AvGrowth = 4.90;
const double Utilities::AvGrowth = 7.70;
const double Retail::AvGrowth = 6.81;
const double Transportation::AvGrowth = 23.45;
const double Industrials::AvGrowth = 14.72;
const double Materials::AvGrowth = -2.96;
const double Telecommunications::AvGrowth = 17.43;
/*Define Static Variables*/

/*carculating forevergrowth*/
double CalculateForevergrowth(double* EPS, double AvGrowth) {
    double score;
    score = ((EPS[2] / EPS[0]) - 1) * 100 + AvGrowth;
    return 2 + 2 * score / 100;
}

Technology::Technology(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double RDexpend) : Stock(ticker, PBR, StockPrice, WACC, EPS), RDExpend(RDexpend){}

void Technology::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (RDExpend > 15) value *= 1.1;
    else if (RDExpend < 10) value *= 0.9;
    valueratio = value / StockPrice;
}

void Technology::PrintStock() {
    cout << Ticker << "::  Sector: Technology\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Revenue Growth Rate" << endl << endl;
}

Healthcare::Healthcare(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, int Patent) : Stock(ticker, PBR, StockPrice, WACC, EPS), Patent(Patent) {}

void Healthcare::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (Patent > 500) value *= 1.1;
    else if (Patent < 100) value *= 0.9;
    valueratio = value / StockPrice;
}

void Healthcare::PrintStock() {
    cout << Ticker << "::  Sector: Healthcare\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Clinical Trials Success Rate" << endl << endl;
}

Financial_Services::Financial_Services(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double NetInterestMargin) : Stock(ticker, PBR, StockPrice, WACC, EPS), NetInterestMargin(NetInterestMargin) {}

void Financial_Services::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (NetInterestMargin > 3) value *= 1.1;
    else if (NetInterestMargin < 1.5) value *= 0.9;
    valueratio = value / StockPrice;
}

void Financial_Services::PrintStock() {
    cout << Ticker << "::  Sector: Financial_Services\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Non-Performing Loans (NPL) Ratio" << endl << endl;
}

Consumer_Goods::Consumer_Goods(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double MarketShare) : Stock(ticker, PBR, StockPrice, WACC, EPS), MarketShare(MarketShare) {}

void Consumer_Goods::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (MarketShare > 25) value *= 1.1;
    else if (MarketShare < 10) value *= 0.9;
    valueratio = value / StockPrice;
}

void Consumer_Goods::PrintStock() {
    cout << Ticker << "::  Sector: Consumer_Goods\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Brand Equity" << endl << endl;
}

Energy::Energy(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double ReservesReplacementRatio) : Stock(ticker, PBR, StockPrice, WACC, EPS), ReservesReplacementRatio(ReservesReplacementRatio) {}

void Energy::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (ReservesReplacementRatio > 1.2) value *= 1.1;
    else if (ReservesReplacementRatio < 1.0) value *= 0.9;
    valueratio = value / StockPrice;
}

void Energy::PrintStock() {
    cout << Ticker << "::  Sector: Energy\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Carbon Emissions Intensity" << endl << endl;
}

Utilities::Utilities(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double ROE) : Stock(ticker, PBR, StockPrice, WACC, EPS), ROE(ROE) {}

void Utilities::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (ROE > 10) value *= 1.1;
    else if (ROE < 5) value *= 0.9;
    valueratio = value / StockPrice;
}

void Utilities::PrintStock() {
    cout << Ticker << "::  Sector: Utilities\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Customer Satisfaction Score" << endl << endl;
}

Retail::Retail(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double SameStoreSaleGrowth) : Stock(ticker, PBR, StockPrice, WACC, EPS), SameStoreSaleGrowth(SameStoreSaleGrowth) {}

void Retail::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (SameStoreSaleGrowth > 10) value *= 1.1;
    else if (SameStoreSaleGrowth < 5) value *= 0.9;
    valueratio = value / StockPrice;
}

void Retail::PrintStock() {
    cout << Ticker << "::  Sector: Retail\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Inventory Turnover Ratio" << endl << endl;
}

Transportation::Transportation(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double LoadFactor) : Stock(ticker, PBR, StockPrice, WACC, EPS), LoadFactor(LoadFactor) {}

void Transportation::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (LoadFactor > 85) value *= 1.1;
    else if (LoadFactor< 70) value *= 0.9;
    valueratio = value / StockPrice;
}

void Transportation::PrintStock() {
    cout << Ticker << "::  Sector: Transportation\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Fuel Efficiency" << endl << endl;
}

Industrials::Industrials(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double CapacityUtilizationRate) : Stock(ticker, PBR, StockPrice, WACC, EPS), CapacityUtilizationRate(CapacityUtilizationRate) {}

void Industrials::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (CapacityUtilizationRate > 85) value *= 1.1;
    else if (CapacityUtilizationRate < 70) value *= 0.9;
    valueratio = value / StockPrice;
}

void Industrials::PrintStock() {
    cout << Ticker << "::  Sector: Industrials\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Order Backlog" << endl << endl;
}

Materials::Materials(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double CommodityPriceIndex) : Stock(ticker, PBR, StockPrice, WACC, EPS), CommodityPriceIndex(CommodityPriceIndex) {}

void Materials::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (CommodityPriceIndex > 150) value *= 1.1;
    else if (CommodityPriceIndex < 100) value *= 0.9;
    valueratio = value / StockPrice;
}

void Materials::PrintStock() {
    cout << Ticker << "::  Sector: Materials\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Production Cost Per Unit" << endl << endl;
}

Telecommunications::Telecommunications(char* ticker, double PBR, double StockPrice, double WACC, double* EPS, double ARPU) : Stock(ticker, PBR, StockPrice, WACC, EPS), ARPU(ARPU) {}

void Telecommunications::Valuation() {
    ForeverGrowth = CalculateForevergrowth(EPS, AvGrowth);
    value = valuation(EPS, AvGrowth, ForeverGrowth, WACC, StockPrice, PBR);
    if (ARPU > 50) value *= 1.1;
    else if (ARPU < 20) value *= 0.9;
    valueratio = value / StockPrice;
}

void Telecommunications::PrintStock() {
    cout << Ticker << "::  Sector: Telecommunications\nStock Price: " << StockPrice << "\tTarget Price: " << value << endl;
    if (valueratio > 1.1) cout << "This Stock is underrated!" << endl;
    else if (valueratio < 0.9) cout << "This Stock is overrated!" << endl;
    else cout << "This Stock has fair value" << endl;
    cout << "Good to consider further: Network Coverage" << endl << endl;
}