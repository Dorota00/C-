//
// Created by Dorota on 12.12.2020.
//

#include "Produkt.h"

int Produkt::IDcounter=0;

int Produkt::setID() {
    return IDcounter++;
}

int Produkt::getID() {
    return productID;
}
