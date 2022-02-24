//
// Created by Dorota on 12.12.2020.
//

#include "Paleciak.h"

bool Paleciak::checkUdzwig() {
    float sum=0;
    for(size_t i=0; i < paleciakVec.size(); i++)
    {
        sum+=paleciakVec.at(i)->getWeight(paleciakVec.at(i));
    }
    if(sum > udzwig){
        cout << "Too much products: " << sum - udzwig << "kg too much" << endl;
        return false;
    }
    cout << "Weight of products on paleciak[kg]: " << sum << endl;
    return true;
}

void Paleciak::addToPaleciak(Produkt *ptr) {
    if(ptr!=nullptr){
        paleciakVec.push_back(ptr);
    }
}
