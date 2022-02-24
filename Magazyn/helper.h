//
// Created by Dorota on 29.11.2020.
//

#ifndef PROJEKT_I_HELPER_H
#define PROJEKT_I_HELPER_H

#include<iostream>
#include<istream>
#include<string>
using namespace std;

int readInt(istream &in);
float readFloat(istream &in);
string readString(istream &in);
char readChar(istream &in);

template <class C>
void isEmpty(C& _class)     // funkcja szablonowa sprawdzajaca czy wektor w podanej klasie jest pusty
{
    if(_class.vec.empty())
    {
        throw(_class);        // rzucanie wyjatku
    }
}

template <typename T>
bool check(T _ID, T min, float max)    // funkcja szablonowa sprawdzajaca czy podana informacja przez uzytkownika jest poprawna
{
    if(_ID < min || _ID >= min + max ) {
        cout << "Out of possible range. Try again" << endl;
        return false;
    }
    return true;
}

#endif //PROJEKT_I_HELPER_H
