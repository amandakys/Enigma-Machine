//
// Created by Andi Koh on 19/10/2016.
//

#include <iostream>
#include "Axle.hpp"

Axle::Axle(int numRotors, Rotor **rotors) {
    this->rotors = rotors;
    this->numRotors = numRotors;
}

void Axle::rotateRotors() {
    for (int i = 0; i < this->numRotors; i++) {
        if (rotors[i]->getRotations() < 25) {
            rotors[i]->rotate();
            break;
        } else if (rotors[i]->getRotations() == 25){
            rotors[i]->rotate();
            rotors[i]->resetRotations();
            //what happens when the final rotor hits 26 rotations
            //should
        }
    }
}

char Axle::encodeOneLR(char in) {
    char current = in;
    for (int i = 0; i < this->numRotors; i++) {
        current = rotors[i]->encodeOneLR(current);
        //cout << current << endl;
    }

    return current;
}

char Axle::encodeOneRL(char in) {
    char current = in;
    for (int i = numRotors - 1; i >= 0; i--) {
        current = rotors[i]->encodeOneRL(current);
//        cout << current << endl;
    }
    rotateRotors();
    return current;
}

string Axle::encodeLR(string in) {
    string out = "";
    for (char &c : in) {
        out += encodeOneLR(c);
    }
    return out;
}

string Axle::encodeRL(string in) {
    string out = "";
    for (char &c : in) {
        out += encodeOneRL(c);
    }
    return out;
}
