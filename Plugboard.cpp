//
// Created by Andi Koh on 15/10/2016.
//

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <map>
#include "Plugboard.hpp"

/*Plugboard::Plugboard(FILE *pbFile) {
    this->pbFile = pbFile;
}*/
using namespace std;

Plugboard::Plugboard(string filename) {
    this->filename = filename;
    this->values = new int[52];
    this->numValues = 0;
    generateIntCharMap();
    this->readfile();
    generateMap();
}

void Plugboard::readfile() {
    ifstream pbFile;
    pbFile.open(this->filename);

    string contents;
    if (pbFile.is_open()) {
        getline(pbFile, contents);
        pbFile.close();
    } else {
        cout << "failure opening file" << endl;
        exit(EXIT_FAILURE);
    }

    string token;
    string delim = " ";
    size_t pos = 0;
    for (int i = 0; i < 52; i++) {
        pos = contents.find(delim);
        if (pos != string::npos) {
            token = contents.substr(0, pos);
            this->values[i] = atoi(token.c_str());
            contents.erase(0, pos + delim.length());
        } else {
            this->numValues = i+1;
            break;
        }
    }

    this->values[numValues - 1] = atoi((contents).c_str());
}

void Plugboard::generateMap() {
    for (int i = 0; i < this->numValues; i+=2) {
        this->valueMap[values[i]] = values[i+1];
        this->valueMap[values[i+1]] = values[i];
    }
}

char Plugboard::encodeOne(char in) {
    char out;
    int lookup = this->charToInt(in);
    map<int, int>::iterator it = valueMap.find(lookup);
    if (it != valueMap.end()) {
        int result = valueMap[lookup];
        out = this->intToChar(result);
    } else {
        //lookup value is not in map
        //value is mapped to itself
        out = in;
    }
    return out;
}

Plugboard::Plugboard() {}
