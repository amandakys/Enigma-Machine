//
// Created by Andi Koh on 19/10/2016.
//

#include <fstream>
#include "Rotor.hpp"

Rotor::Rotor(string filename) {
    this->filename = filename;
    this->values = new int[26];
    generateIntCharMap();
    readfile();
}

void Rotor::readfile() {
    ifstream rotorFile;
    rotorFile.open(this->filename);

    string contents;
    if (rotorFile.is_open()) {
        getline(rotorFile, contents);
        rotorFile.close();
    }

    string token;
    string delim = " ";
    size_t pos = 0;
    //contents = "23 6 9 5 21 0 18 8 1 11 24 4 14 20 12 3 10 25 7 17";
    for (int i = 0; i < 26; i++) {
        pos = contents.find(delim);
        if (pos != string::npos) {
            token = contents.substr(0, pos);
            this->values[i] = atoi(token.c_str());
            contents.erase(0, pos + delim.length());
        } else {
            break;
        }
    }

    this->values[25] = atoi((contents).c_str());
}

void Rotor::rotate() {
    int save = values[0];
    for (int i = 0; i < 25; i++) {
        int r = values[i + 1];
        if (r - 1 < 0) {
            values[i] = 25;
        } else {
            values[i] = r;
        }
    }
    if (save - 1 < 0) {
        values[25] = 25;
    } else {
        values[25] = save - 1;
    }

    this->numRotations++;
}

char Rotor::encodeOne(char in) {
    char out;
    int lookup = this->charToInt(in);
    int result = this->values[lookup];
    out = this->intToChar(result);
    return out;
}

void Rotor::resetRotations() {
    this->numRotations = 0;
}

int Rotor::getRotations() {
    return this->numRotations;
}

Rotor::Rotor() {

}
