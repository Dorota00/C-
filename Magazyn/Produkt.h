//
// Created by Dorota on 12.12.2020.
//

#ifndef ZUBDOROTA_ETAP2_PRODUKT_H
#define ZUBDOROTA_ETAP2_PRODUKT_H

#include<iostream>
#include<istream>
#include<string>
using namespace std;

class Produkt {       // klasa abstrakcyjna
public:
    explicit Produkt(string _productName): productName(move(_productName)){
        productID= setID();
    }
    Produkt();
    virtual ~Produkt(){}
    virtual Produkt* divide(istream &s)=0;            // funkcja czysto wirtualna
    virtual void merge(istream &in, Produkt* ptr)=0;
    virtual float getWeight(Produkt* ptr)=0;
    virtual void printProduct()=0;
    virtual Produkt* clone(float number)=0;

    int getID();
    static int IDcounter;     // statyczny licznik klasy
protected:
    int productID;
    string productName;

private:
    static int setID();     // nadawanie unikalnego ID
};


#endif //ZUBDOROTA_ETAP2_PRODUKT_H
