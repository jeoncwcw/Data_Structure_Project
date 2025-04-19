#define _CRT_SECURE_NO_WARNINGS
#include "List.h"
#include<iostream>
#include <cstring>
#include <limits>
#include <string>
using namespace std;

int main() {
    string strTicker;
    double PBR;
    double StockPrice;
    double WACC;
    double EPS[3];
    int sector;
    List list;
    while(true) {
        cout << "Type Ticker of the Stock which you want to investigate. (If you want to finish, just type enter.): " << endl;
        getline(cin, strTicker);
        if (strTicker.empty()) break;
        const char* c_str = strTicker.c_str();
        char* Ticker = new char[strTicker.length() + 1];
        strcpy(Ticker, c_str);
        //get Ticker of Stock

        cout << "Type PBR of your Stock (Please refer to this: https://www.choicestock.co.kr/search/invest/(Ticker))" << endl;
        cin >> PBR;
        // get PBR of Stock

        cout << "Type Price of your Stock" << endl;
        cin >> StockPrice;
        // get Price of Stock

        cout << "Type WACC of your Stock (Please refer to this: https://valueinvesting.io/(Ticker)/valuation/wacc)" << endl;
        cin >> WACC;
        // get WACC of Stock

        cout << "Type Forward EPS of your Stock (Please refer to this: https://www.marketwatch.com/investing/stock/(Ticker)/analystestimates)" << endl;
        cout << "2024: ";
        cin >> EPS[0];
        cout << "2025: ";
        cin >> EPS[1];
        cout << "2026: ";
        cin >> EPS[2];
        // get Forward EPS of Stock

        cout << "Please select Sector of your stock. (Just type Number)" << endl;
        cout << "1.Technology" << endl << "2.Healthcare" << endl << "3.Financial Services" << endl << "4.Consumer Goods" << endl << "5.Energy" << endl << "6.Utilities" << endl << "7.Retail" << endl << "8.Transportation" << endl << "9.Industrials" << endl << "10.Materials" << endl << "11.Telecommunications" << endl;
        cin >> sector;
        // get Sector of Stock
        Stock* newStock;
        switch (sector)
        {
        case 1:
            double RDexpenditure;
            cout << "Please type Expenditure ratio of your Stock (If you don't know, just type ""12"")" << endl;
            cin >> RDexpenditure;
            newStock = new Technology(Ticker, PBR, StockPrice, WACC, EPS, RDexpenditure);
            break;
        case 2:
            int PatentPortfolio;
            cout << "Please type Number of Active patents held (If you don't know, just type ""200"")" << endl;
            cin >> PatentPortfolio;
            newStock = new Healthcare(Ticker, PBR, StockPrice, WACC, EPS, PatentPortfolio);
            break;
        case 3:
            double NetInterestMargin;
            cout << "Please type Net Interest Margin (If you don't know, just type ""2"")" << endl;
            cin >> NetInterestMargin;
            newStock = new Financial_Services(Ticker, PBR, StockPrice, WACC, EPS, NetInterestMargin);
            break;
        case 4:
            double MarketShare;
            cout << "Please type Market Share of your company (If you don't know, just type ""20"")" << endl;
            cin >> MarketShare;
            newStock = new Consumer_Goods(Ticker, PBR, StockPrice, WACC, EPS, NetInterestMargin);
            break;
        case 5:
            double ReservesReplacementRatio;
            cout << "Please type Ratio of new reserves to production (If you don't know, just type ""1.1"")" << endl;
            cin >> ReservesReplacementRatio;
            newStock = new Energy(Ticker, PBR, StockPrice, WACC, EPS, ReservesReplacementRatio);
            break;
        case 6:
            double ROE;
            cout << "Please type ROE of your Stock (If you don't know, just type ""7"")" << endl;
            cin >> ROE;
            newStock = new Utilities(Ticker, PBR, StockPrice, WACC, EPS, ROE);
            break;
        case 7:
            double SameStoreGrowth;
            cout << "Please type YOY growth in sales from same store (If you don't know, just type ""7"")" << endl;
            cin >> SameStoreGrowth;
            newStock = new Retail(Ticker, PBR, StockPrice, WACC, EPS, SameStoreGrowth);
            break;
        case 8:
            double LoadFactor;
            cout << "Please type percentage of available seats that are filled with passenger (If you don't know, just type ""80"")" << endl;
            cin >> LoadFactor;
            newStock = new Transportation(Ticker, PBR, StockPrice, WACC, EPS, LoadFactor);
            break;
        case 9:
            double CapacityUtilizationRate;
            cout << "Please type Percentage of total production capacity being used (If you don't know, just type ""120"")" << endl;
            cin >> CapacityUtilizationRate;
            newStock = new Industrials(Ticker, PBR, StockPrice, WACC, EPS, CapacityUtilizationRate);
            break;
        case 10:
            double CommodityPriceIndex;
            cout << "Please type average price of Commodity Index (If you don't know, just type ""120"")" << endl;
            cin >> CommodityPriceIndex;
            newStock = new Materials(Ticker, PBR, StockPrice, WACC, EPS, CommodityPriceIndex);
            break;
        case 11:
            double ARPU;
            cout << "Please type average revenue per user (If you don't know, just type ""30"")" << endl;
            cin >> ARPU;
            newStock = new Telecommunications(Ticker, PBR, StockPrice, WACC, EPS, ARPU);
            break;
        default:
            cout << "You've inserted wrong sector. Please do it again";
            return 0;
        }
        newStock->Valuation();
        list.Insert(newStock);
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    list.Print();
}
