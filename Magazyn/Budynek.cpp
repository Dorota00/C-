//
// Created by Dorota on 17.12.2020.
//

#include "Budynek.h"

Budynek::~Budynek() {
    for(size_t i=0; i < vec.size(); i++)
        delete vec.at(i);
}

void Budynek::createStock(istream &in) {
    cout << "Stock name:";
    string _name = readString(in);
    Magazyn* m = new Magazyn(_name);
    vec.push_back(m);
}

int Budynek::chooseStock(istream &in) {
    ::isEmpty(*this);

    cout << "Stock ID:";
    char _ID= readChar(in);
    while(!check(_ID, 'A', vec.size())){
        _ID= readChar(in);
    }
    return (int) (_ID - 'A');
}

void Budynek::printBudynek() {
    cout << "Created stocks:" << endl << "......................." << endl;
    for(size_t i=0; i < vec.size(); i++)
    {
        cout << i+1 << ". Name: " << vec.at(i)->stockName << " ID: " << vec.at(i)->stockID << endl;
    }
    cout << "......................." << endl;
}
