//
// Created by Andi Koh on 19/10/2016.
//

#include <fstream>
#include "Rotor.hpp"
#include "utilities.hpp"

Rotor::Rotor(string filename) {
    this->filename = filename;
    this->values = new int[NUMLETTERS];
    this->inverse = new int[NUMLETTERS];
    this->numRotations = 0;
    generateIntCharMap();
    readfile();
    generateInverse();
}

void Rotor::readfile() {
    ifstream rotorFile;
    rotorFile.open(this->filename);

    string contents;
    if (rotorFile.is_open()) {
        getline(rotorFile, contents);
        rotorFile.close();
    }
    //separate values from rotor file based on " "
    //save into values array values[0..25]
    string token;
    string delim = " ";
    size_t pos = 0;
    for (int i = 0; i < NUMLETTERS; i++) {
        pos = contents.find(delim);
        if (pos != string::npos) {
            token = contents.substr(0, pos);
            this->values[i] = atoi(token.c_str());
            contents.erase(0, pos + delim.length());
        } else {
            break;
        }
    }
    //need to manually insert last value
    this->values[INPUT_Z] = atoi((contents).c_str());
}

void Rotor::generateInverse() {
    //create inverse mapping for when value goes back through rotor
    for (int i = 0; i < NUMLETTERS; i++) {
        this->inverse[values[i]] = i;
    }
}

void Rotor::rotate() {
    //save mapping of A
    int save = values[INPUT_A];
    for (int i = 0; i < INPUT_Z; i++) {
        //for A - Y, new mapping is mapping of the next value - 1
        int r = values[i + 1]; //calculate new mapping
        if (r - 1 < INPUT_A) { //if new mapping is negative, must wrap around
            values[i] = INPUT_Z; //-1 mapping equivalent to mapping to Z (25)
        } else {
            values[i] = r - 1;
        }
    }
    //mapping of Z (25) is mapping of A - 1
    //if negative then wrap around to Z
    if (save - 1 < INPUT_A) {
        values[INPUT_Z] = INPUT_Z;
    } else {
        values[INPUT_Z] = save - 1;
    }
    //after every rotation, generate new inverse mapping
    generateInverse();

    this->numRotations++;
}

char Rotor::encodeOneLR(char in) {
    //for first pass through rotors
    char out;
    int lookup = this->charToInt(in);
    int result = this->values[lookup];
    out = this->intToChar(result);
    return out;
}

char Rotor::encodeOneRL(char in) {
    //for return through rotors
    char out;
    int lookup = this->charToInt(in);
    int result = inverse[lookup];
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

char Rotor::encodeOne(char in) {
    return '\0';
}
