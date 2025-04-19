#include"List.h"
#include <iostream>
using namespace std;

List::List() {
    head = NULL;
}
List::~List() {
    Stock* iterator = head;
    while (iterator != NULL) {
        head = iterator->getNext();
        delete iterator;
        iterator = head;
    }
}
void List::Insert(Stock* newStock) {
    if (head == NULL) {
        head = newStock;
        return;
    }
    if (newStock->getValueRatio() > head->getValueRatio()) {
        newStock->setNext(head);
        head = newStock;
        return;
    }
    Stock* iterator = head->getNext();
    Stock* PrevNode = head;
    while (iterator != NULL) {
        if (newStock->getValueRatio() > iterator->getValueRatio()) {
            PrevNode->setNext(newStock);
            newStock->setNext(iterator);
            return;
        }
        iterator = iterator->getNext();
        PrevNode = PrevNode->getNext();
    }
    PrevNode->setNext(newStock);
    return;
}
void List::Print() {
    Stock* PrintNode = head;
    while (PrintNode != NULL) {
        PrintNode->PrintStock();
        PrintNode = PrintNode->getNext();
    }
}