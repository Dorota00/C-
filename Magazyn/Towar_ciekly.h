//
// Created by Dorota on 12.12.2020.
//

#ifndef ZUBDOROTA_ETAP2_TOWAR_CIEKLY_H
#define ZUBDOROTA_ETAP2_TOWAR_CIEKLY_H

#include<iostream>
#include<istream>
#include"Produkt.h"
#include"helper.h"

class Towar_ciekly: public Produkt {
public:
    explicit Towar_ciekly(string _productName):Produkt(move(_productName)), amount(0){
        cout << "Created product: " << endl << this;
    }
    Towar_ciekly(Towar_ciekly &t);

    friend ostream &operator<<(ostream &out, Towar_ciekly *towarCptr);
    void operator +=(float amount);       // przeladowne operatory
    void operator -=(float amount);

    Produkt* divide(istream &in) override;
    void merge(istream &in, Produkt* ptr) override;
    float getWeight(Produkt* ptr) override;
    void printProduct() override;
    Produkt* clone(float number) override;

protected:
    float amount;
};


#endif //ZUBDOROTA_ETAP2_TOWAR_CIEKLY_H
