//
// Created by Andi Koh on 16/10/2016.
//

#include <string>
#include <cstdlib>
#include <iostream>
#include "Component.hpp"
#include "utilities.hpp"

using namespace std;

Component::Component() {
    generateIntCharMap();
}

void Component::generateIntCharMap() {
    //used to relate ints 0 - 25 to chars A - Z
    char c = 'A';
    for (int i = 0; i < NUMLETTERS; i++) {
        this->intCharMap[i] = (char) (c + i);
    }
}
char Component::intToChar(int i) {
    if (i >= INPUT_A && i <= INPUT_Z) {
        return this->intCharMap[i];
    } else {
        perror("invalid input integer");
        return (char) i;
    }
}

int Component::charToInt(char c) {
    int i = (int) c;
    if (i >= ASCII_A && i <= ASCII_Z){
        //uppercase
        i -= ASCII_A;
    } else {
        //lowercase
        cout << "Only upper case letters allowed for input" << endl;
        exit(EXIT_FAILURE);
    }

    return i;
}


char Component::encodeOne(char in) {
    return 0;
}

