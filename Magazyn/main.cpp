
#include<fstream>
#include<iostream>
#include<string>
#include"Budynek.h"

using namespace std;

void menu();
bool choose(istream &in, Budynek& budynek, Paleciak &paleciak);

int main(int argc, char* argv[]) {

    bool file=0;
    ifstream fin;
    Budynek budynek;
    Paleciak paleciak;

    if(argc > 1 ){
        file=1;
        fin.open(argv[1]);
    }

    menu();

    if(file && fin){
        ifstream fin(argv[1]);
        cout << "Reading from file"<< endl
                << "......................." << endl;
        while (!fin.eof() && choose(fin,budynek,paleciak)){
        }
        fin.close();
    }else{
        cout << "Could not open the file. Reading from std::cin" << endl
             << "......................." << endl;
        while(choose(cin,budynek,paleciak)){
            menu();
        }
    }

    cout << "Program " << argv[0] << " ended";

}

void menu(){
    cout << "......................." << endl
         << "STOCK REGISTER" << endl
         << "......................." << endl
         << "Choose option:" << endl
         << "1 - create new stock" << endl
         << "2 - register new product" << endl
         << "3 - product entry" << endl
         << "4 - product removal" << endl
         << "5 - stock balance" << endl
         << "6 - view created stocks" << endl
         << "7 - end" << endl
         << "......................." << endl;
}

bool choose(istream &in, Budynek& budynek, Paleciak &paleciak) {

    int choice = readInt(in);
    try {
        switch (choice) {

            case 1: {
                budynek.createStock(in);
                return true;
            }
            case 2: {
                budynek.vec.at(budynek.chooseStock(in))->createProduct(in);
                return true;
            }
            case 3: {
                int _ID = budynek.chooseStock(in);
                paleciak.addToPaleciak(budynek.vec.at(_ID)->cloneProduct(in));

                budynek.vec.at(_ID)->addProduct(in, paleciak);

                return true;
            }
            case 4: {
                budynek.vec.at(budynek.chooseStock(in))->removeProduct(in, paleciak);
                return true;
            }
            case 5: {

                budynek.vec.at(budynek.chooseStock(in))->printStock();
                return true;
            }
            case 6: {
                budynek.printBudynek();
                return true;
            }
            case 7: {
                return false;
            }

            default: {
                cout << "Wrong option" << endl;
                return true;
            }
        }

    }
    catch (Magazyn)
    {                                                               // lapanie wyjatku
        cout << "There is no registered product. Back to the menu" << endl;
        return true;
    }

    catch (Budynek)
    {
        cout << "There is no registered stock. Back to menu" << endl;
        return true;
    }

    catch (...) {
        cout << "Unknown exception" << endl;
        return true;
    }

}

