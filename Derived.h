#pragma once
#include"Stock.h"
#ifndef DERIVED_H
#define DERIVED_H

class Technology : public Stock {
public:
    Technology(char*, double, double, double, double*, double);
    virtual ~Technology() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double RDExpend;
};
class Healthcare : public Stock {
public:
    Healthcare(char*, double, double, double, double*, int);
    virtual ~Healthcare() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const int Patent;
};
class Financial_Services : public Stock {
public:
    Financial_Services(char*, double, double, double, double*, double);
    virtual ~Financial_Services() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double NetInterestMargin;
};
class Consumer_Goods : public Stock {
public:
    Consumer_Goods(char*, double, double, double, double*, double);
    virtual ~Consumer_Goods() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double MarketShare;
};
class Energy : public Stock {
public:
    Energy(char*, double, double, double, double*, double);
    virtual ~Energy() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double ReservesReplacementRatio;
};
class Utilities : public Stock {
public:
    Utilities(char*, double, double, double, double*, double);
    virtual ~Utilities() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double ROE;
};
class Retail : public Stock {
public:
    Retail(char*, double, double, double, double*, double);
    virtual ~Retail() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double SameStoreSaleGrowth;
};
class Transportation : public Stock {
public:
    Transportation(char*, double, double, double, double*, double);
    virtual ~Transportation() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double LoadFactor;
};
class Industrials : public Stock {
public:
    Industrials(char*, double, double, double, double*, double);
    virtual ~Industrials() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double CapacityUtilizationRate;
};
class Materials : public Stock {
public:
    Materials(char*, double, double, double, double*, double);
    virtual ~Materials() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double CommodityPriceIndex;
};
class Telecommunications : public Stock {
public:
    Telecommunications(char*, double, double, double, double*, double);
    virtual ~Telecommunications() {}
    virtual void Valuation();
    virtual void PrintStock();
private:
    static const double AvGrowth;
    const double ARPU;
};
#endif