//
// Created by Dorota on 16.11.2020.
//

#ifndef PROJEKT_I_MAGAZYN_H
#define PROJEKT_I_MAGAZYN_H

#include<istream>
#include<iostream>
#include<vector>
#include<string>
#include"Paleciak.h"
#include"Produkt.h"
#include"helper.h"
#include"chooseType.h"
using namespace std;

class Magazyn {
public:
    vector<Produkt*> vec;
   explicit Magazyn(string _stockName):stockName(move(_stockName)){
       stockID=setID();
       cout << "Created stock: " << stockName << " with ID: " << stockID << endl;
   }
   ~Magazyn();

   void createProduct(istream &in);
   void addProduct(istream &in, Paleciak& paleciak);       // metoda przyjmij
   void removeProduct(istream &in, Paleciak& paleciak);     // metoda wydaj
   Produkt* cloneProduct(istream &in);
   void printStock();            // drukukowanie stanu magazynu

 private:
    char stockID;
    string stockName;

    static char counterStockID; // statyczna skladowa
    static char setID();

    size_t findProduct(int _ID);

    friend class Budynek;
};



#endif //PROJEKT_I_MAGAZYN_H
