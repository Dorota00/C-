//
// Created by Dorota on 29.11.2020.
//
#include"helper.h"

int readInt(istream &in) {
    string line;
    getline(in, line);
    return atoi(line.c_str());
}
float readFloat(istream &in)
{
    string line;
    getline(in, line);
    return stof(line);       // konwersja: string do float
}

string readString(istream &in){
    string line;
    getline(in, line);
    return line;
}
char readChar(istream &in){
    string stringID=readString(in);
    return stringID.front();
}



