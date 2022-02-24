//
// Created by Dorota on 20.12.2020.
//

#include "chooseType.h"

Produkt* chooseType(istream &in){
    cout << "Product name:";
    string _productName=readString(in);

    cout << "Type of product:"<< endl
         << "1 - towar" << endl
         << "2 - towar sypki" << endl
         << "3 - towar ciekly"<< endl;
while(1){
    int choice= readInt(in);

    switch (choice){
        case 1: {
            cout << "Weight of one product[kg]:";         // waga jednego egzemplarza Towaru
            float weight=readFloat(in);
            float min=0;
            while(!check(weight,min,1000)){
                weight=readFloat(in);
            }
            return new Towar(_productName, weight);
        }
        case 2: {
            return new Towar_sypki(_productName);
        }
        case 3: {
            return new Towar_ciekly(_productName);
        }
        default: {
            cout << "Wrong option " << endl;
        }
    }
}

}
