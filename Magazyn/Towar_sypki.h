//
// Created by Dorota on 12.12.2020.
//

#ifndef ZUBDOROTA_ETAP2_TOWAR_SYPKI_H
#define ZUBDOROTA_ETAP2_TOWAR_SYPKI_H

#include<iostream>
#include<istream>
#include"Produkt.h"
#include"helper.h"

class Towar_sypki:public Produkt {
public:
    explicit Towar_sypki(string _productName): Produkt(move(_productName)), amount(0){
        cout << "Created product: " << endl << this;
    }
    Towar_sypki(Towar_sypki &t);
    friend ostream &operator<<(ostream &out, Towar_sypki *towarSptr);
    void operator +=(float number);       // przeladowne operatory
    void operator -=(float number);

    Produkt* divide(istream &in) override;
    void merge(istream &in, Produkt* ptr) override;
    float getWeight(Produkt* ptr) override;
    void printProduct() override;
    Produkt* clone(float number) override;

protected:
    float amount;
};


#endif //ZUBDOROTA_ETAP2_TOWAR_SYPKI_H
