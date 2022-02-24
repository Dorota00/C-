//
// Created by Dorota on 16.11.2020.
//

#include "Magazyn.h"

char Magazyn::counterStockID='A';

char Magazyn::setID() {
    return counterStockID++;
}

Magazyn::~Magazyn() {
    for(size_t i=0; i < vec.size(); i++)
        delete vec.at(i);
}

void Magazyn::printStock() {
    cout << "Stock " << stockName << " with ID " << stockID << " balance: " <<  endl
            << "......................." << endl;

    for(size_t i=0; i < vec.size(); i++)
    {
        cout << i+1 <<". ";
        vec.at(i)->printProduct();    // metoda at zwraca element z podanej pozycji
    }
    cout << "......................." << endl;
}

void Magazyn::createProduct(istream &in){
    vec.push_back(chooseType(in));          // metoda wstawiajaca element na koncu
}

Produkt* Magazyn::cloneProduct(istream &in) {
    ::isEmpty(*this);

    cout << "Product ID:";
    int _ID= readInt(in);
    while(!check(_ID, 0, Produkt::IDcounter)){
        _ID= readInt(in);
    }

    cout << "Number or amount of added product:";
    float number = readFloat(in);
    float min=0;
    while (!check(number,min,1000)) {
        cout << "Wrong number.Try again" << endl;
        number = readFloat(in);
    }

    int i= findProduct(_ID);
    if(i!=-1)
    {
        return vec.at(i)->clone(number);
    }
    return nullptr;

}

void Magazyn::addProduct(istream &in, Paleciak& paleciak) {

    ::isEmpty(*this);

    size_t j;
    if (paleciak.checkUdzwig()) {
        for (size_t i=0; i < paleciak.paleciakVec.size(); i++) {
            int _ID = paleciak.paleciakVec.at(i)->getID();

            j= findProduct(_ID);
            if(j!=-1){
                vec.at(j)->merge(in, paleciak.paleciakVec.at(i));
                cout << "Current condition: " << endl;
                vec.at(j)->printProduct();
            }

        }
    }
    paleciak.paleciakVec.clear();

}
void Magazyn::removeProduct(istream &in, Paleciak& paleciak){

    ::isEmpty(*this);

    cout << "Product ID:";
    int _ID= readInt(in);
    while(!check(_ID, 0, Produkt::IDcounter)){
        _ID= readInt(in);
    }
    size_t i= findProduct(_ID);

    paleciak.addToPaleciak(vec.at(i)->divide(in));

    if(!paleciak.checkUdzwig()){
        vec.at(i)->merge(in, vec.at(i));
        return;
    }
    paleciak.paleciakVec.clear();           // metoda czyszczaca wektor

   cout << "Current condition: " << endl;
   vec.at(i)->printProduct();
}

size_t Magazyn::findProduct(int _ID) {
    for(size_t i=0; i < vec.size(); i++) {
        if (vec.at(i)->getID() == _ID) {
            return i;
        }
    }
    cout << "There is no product in this Stock with given ID" << endl;
    return -1;
}
