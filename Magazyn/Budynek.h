//
// Created by Dorota on 17.12.2020.
//

#ifndef ZUBDOROTA_ETAP2_BUDYNEK_H
#define ZUBDOROTA_ETAP2_BUDYNEK_H

#include<iostream>
#include<istream>
#include<vector>
#include<string>
#include"Magazyn.h"
using namespace std;

class Budynek {
public:
    vector<Magazyn*> vec;

    Budynek(){
        cout << "Welcome" << endl;
    }
    ~Budynek();

    void createStock(istream &in);
    int chooseStock(istream &in);
    void printBudynek();

};

#endif //ZUBDOROTA_ETAP2_BUDYNEK_H
