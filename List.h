#pragma once
#include"Derived.h"
#ifndef LIST_H
#define LIST_H
#endif

class List {
private:
    Stock* head;
public:
    List();
    ~List();
    void Insert(Stock*);
    void Print();
};