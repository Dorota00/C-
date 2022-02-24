//
// Created by Dorota on 12.12.2020.
//

#include "Towar_sypki.h"

Towar_sypki::Towar_sypki(Towar_sypki &t):Produkt(t) {
    productName=t.productName;
    productID=t.productID;
    amount=0;
}
Produkt *Towar_sypki::clone(float number) {
    Towar_sypki* towarSptr=new Towar_sypki(*this);
    towarSptr->amount=number;
    return towarSptr;
}

ostream &operator<<(ostream &out, Towar_sypki* towarSptr) {
    return out << "ID: " << towarSptr->productID << ", product name: " << towarSptr->productName <<
               ", amount: " << towarSptr->amount << "kg" << endl << endl;
}

void Towar_sypki::operator+=(float number) {
    amount += number;
}

void Towar_sypki::operator-=(float number) {
    amount -= number;
}

Produkt *Towar_sypki::divide(istream &in) {
    cout << "Number of removed products:";
    float number=readFloat(in);
    float min=0;
    while(!check(number,min,amount))
    {
        cout << "Wrong number. Try again" << endl;
        number=readFloat(in);
    }

    Towar_sypki* towarSptr=dynamic_cast<Towar_sypki*>(clone(number));

    amount-=number;

    return towarSptr;
}
void Towar_sypki::merge(istream &in, Produkt *ptr) {
    Towar_sypki* towarSptr=dynamic_cast<Towar_sypki*>(ptr);
    amount += towarSptr->amount;
    delete ptr;
}


float Towar_sypki::getWeight(Produkt *ptr) {
    Towar_sypki* towarSptr =dynamic_cast<Towar_sypki*>(ptr);
    return towarSptr->amount;
}

void Towar_sypki::printProduct() {
    cout << this;
}

