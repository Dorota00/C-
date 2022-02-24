//
// Created by Dorota on 12.12.2020.
//

#include "Towar_ciekly.h"

Towar_ciekly::Towar_ciekly(Towar_ciekly &t):Produkt(t) {
    productName=t.productName;
    productID=t.productID;
    amount=0;
}
Produkt *Towar_ciekly::clone(float number) {
    Towar_ciekly* towarCptr=new Towar_ciekly(*this);
    towarCptr->amount=number;
    return towarCptr;
}

ostream &operator<<(ostream &out, Towar_ciekly *towarCptr) {
    return out << "ID: " << towarCptr->productID << ", product name: " << towarCptr->productName <<
               ", amount: " << towarCptr->amount << "l" << endl << endl;
}

void Towar_ciekly::operator+=(float number) {
    amount += number;
}

void Towar_ciekly::operator-=(float number) {
    amount -= number;
}

Produkt *Towar_ciekly::divide(istream &in) {
    cout << "Number of removed products:";
    float number=readFloat(in);
    float min=0;
    while(!check(number,min,amount))
    {
        cout << "Wrong number. Try again" << endl;
        number=readFloat(in);
    }

    Towar_ciekly* towarCptr=dynamic_cast<Towar_ciekly*>(clone(number));

    amount-=number;


    return towarCptr;
}

void Towar_ciekly::merge(istream &in, Produkt *ptr) {
    Towar_ciekly* towarCptr=dynamic_cast<Towar_ciekly*>(ptr);
    amount += towarCptr->amount;
    delete ptr;
}

float Towar_ciekly::getWeight(Produkt *ptr) {
    Towar_ciekly* towarCptr =dynamic_cast<Towar_ciekly*>(ptr);
    return towarCptr->amount;
}

void Towar_ciekly::printProduct() {
    cout << this;
}
