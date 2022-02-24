//
// Created by Dorota on 12.12.2020.
//

#ifndef ZUBDOROTA_ETAP2_PALECIAK_H
#define ZUBDOROTA_ETAP2_PALECIAK_H

#include<iostream>
#include<vector>
#include "Produkt.h"
using namespace std;

class Paleciak {
public:
    vector<Produkt*> paleciakVec;
    bool checkUdzwig();
    void addToPaleciak(Produkt* ptr);

private:
    const int udzwig=100;
};


#endif //ZUBDOROTA_ETAP2_PALECIAK_H
