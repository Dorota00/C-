//
// Created by Dorota on 16.11.2020.
//

#include "Towar.h"

Towar::Towar(Towar &t):Produkt(t) {
    productName=t.productName;
    productID=t.productID;
    numberOfItems=0;
    weight=t.weight;
}

Produkt *Towar::clone(float number) {
    Towar* towarPtr=new Towar(*this);
    towarPtr->numberOfItems=(int)number;
    return towarPtr;
}

ostream &operator<<(ostream &out, Towar *towarPtr) {
    return out << "ID: " << towarPtr->productID << ", product name: " << towarPtr->productName <<
               ", number of items: " << towarPtr->numberOfItems << endl << endl;
}

void Towar::operator+=(int number) {
    numberOfItems+=number;
}
void Towar::operator-=(int number) {
    numberOfItems-=number;
}

Produkt* Towar::divide(istream &in) {
    cout << "Number of removed products:";
    int number= readInt(in);

    while(!check(number,0,numberOfItems))
    {
        cout << "Wrong number. Try again" << endl;
        number= readInt(in);
    }

    Towar* towarPtr=dynamic_cast<Towar*>(clone(number));

    numberOfItems-=number;

    return towarPtr;
}

void Towar::merge(istream &in, Produkt* ptr) {
    Towar* towarPtr=dynamic_cast<Towar*>(ptr);
    numberOfItems += towarPtr->numberOfItems;
    delete ptr;
}

float Towar::getWeight(Produkt *ptr) {
    Towar* towarPtr =dynamic_cast<Towar*>(ptr);
    return (towarPtr->numberOfItems) * (towarPtr->weight);
}

void Towar::printProduct() {
    cout << this;
}
