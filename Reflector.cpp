//
// Created by Andi Koh on 19/10/2016.
//
#include <string>
#include "Reflector.hpp"

using namespace std;

char Reflector::encodeOne(char in) {
    int i = this->charToInt(in);
    i = (i + 13) % 26;
    char out = this->intToChar(i);
    return out;
}




