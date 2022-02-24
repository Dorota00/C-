//
// Created by Dorota on 16.11.2020.
//

#ifndef PROJEKT_I_TOWAR_H
#define PROJEKT_I_TOWAR_H

#include<iostream>
#include<istream>
#include"Produkt.h"
#include"helper.h"
using namespace std;

class Towar: public Produkt {
public:
    explicit Towar(string _productName,float _weight):Produkt(move(_productName)),numberOfItems(0),weight(_weight){     // kontruktor wywoływwany tylko jawnie
        cout << "Created product: " << endl << this;
    }
    Towar( Towar& t);    // kontruktor kopiujacy

    friend ostream &operator<<(ostream &out, Towar* towarPtr);
    void operator +=(int number);       // przeladowne operatory
    void operator -=(int number);

    Produkt* divide(istream &in) override;                  // metoda podziel
    void merge(istream &in, Produkt* ptr) override;         // metoda scal
    float getWeight(Produkt* ptr) override;
    void printProduct() override;
    Produkt* clone(float number) override;

protected:
    int numberOfItems;
    float weight;
};


#endif //PROJEKT_I_TOWAR_H
