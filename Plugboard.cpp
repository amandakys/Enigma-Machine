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
    //this->pbFile = pbFile;
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
    //contents = "23 6 9 5 21 0 18 8 1 11 24 4 14 20 12 3 10 25 7 17";
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
/*void Plugboard::readfile() {
    int numValues = 52; //should only return this if never enters if statement
    for (int i = 0; i < 52; i++) {
        int value;
        if (fscanf(pbFile, "%i", &value) != 1) {
            numValues = i;
            break; //file finished
        }
        values[i] = value;
    }
    this->numValues = numValues;
}*/

void Plugboard::generateMap() {
    for (int i = 0; i < this->numValues; i+=2) {
        this->valueMap[values[i]] = values[i+1];
        this->valueMap[values[i+1]] = values[i];
    }
}

char Plugboard::encodeOne(char in) {
    //we should have a look up table for alphabet conversion to numbers available to all encoding components
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

/*void Plugboard::generateIntCharMap() {
    char c = 'A';
    for (int i = 0; i < 26; i++) {
        this->intCharMap[i] = (char) (c + i);
    }
}
char Plugboard::intToChar(int i) {
    if (i >= 0 && i <= 25) {
        return this->intCharMap[i];
    } else {
        perror("invalid input integer");
    }
}

int Plugboard::charToInt(char c) {
    int i = (int) c;
    if (i >= 97 && i <= 122) {
        //lowercase
        i -=97;
    } else if (i >= 65 && i <= 90){
        //uppercase
        i -= 65;
    }

    return i;
}*/

void Plugboard::printValues() {
   for (int i = 0; i < this->numValues; i++) {
       cout << this->values[i] << endl;
   }
}

Plugboard::Plugboard() {}
