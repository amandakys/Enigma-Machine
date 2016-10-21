//
// Created by Andi Koh on 19/10/2016.
//

#include "Axle.hpp"
#include "utilities.hpp"

Axle::Axle(int numRotors, Rotor **rotors) {
    this->rotors = rotors;
    this->numRotors = numRotors;
}

void Axle::rotateRotors() {
    //manages rotations of all rotors on axle
    for (int i = 0; i < this->numRotors; i++) {
        //if rotor has not reached 26th rotation, rotate and exit
        if (rotors[i]->getRotations() < FULL_ROTATION) {
            rotors[i]->rotate();
            break;
        } else if (rotors[i]->getRotations() == FULL_ROTATION){
            //if rotors has reached 26th rotation
            //rotate rotor, reset numRotations to 0
            //continue in for loop so that next rotor also rotates before exiting
            rotors[i]->rotate();
            rotors[i]->resetRotations();
        }
    }
}

char Axle::encodeOneLR(char in) {
    //passes input through encodeOneLR function of each rotor on axle
    char current = in;
    for (int i = 0; i < this->numRotors; i++) {
        current = rotors[i]->encodeOneLR(current);
    }

    return current;
}

char Axle::encodeOneRL(char in) {
    //passes input through encodeOneRL function of each rotor on axle
    char current = in;
    for (int i = numRotors - 1; i >= 0; i--) {
        current = rotors[i]->encodeOneRL(current);
    }
    //rotate rotors after input char returns through the rotors
    rotateRotors();
    return current;
}


