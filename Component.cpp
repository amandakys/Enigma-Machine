//
// Created by Andi Koh on 16/10/2016.
//

#include <string>
#include "Component.hpp"

using namespace std;

Component::Component() {
    generateIntCharMap();
}
void Component::generateIntCharMap() {
    char c = 'A';
    for (int i = 0; i < 26; i++) {
        this->intCharMap[i] = (char) (c + i);
    }
}
char Component::intToChar(int i) {
    if (i >= 0 && i <= 25) {
        return this->intCharMap[i];
    } else {
        perror("invalid input integer");
        return (char) i;
    }
}

int Component::charToInt(char c) {
    int i = (int) c;
    if (i >= 97 && i <= 122) {
        //lowercase
        i -=97;
    } else if (i >= 65 && i <= 90){
        //uppercase
        i -= 65;
    }

    return i;
}


char Component::encodeOne(char in) {
    return 0;
}

/*string Component::encodeWord(string in) {
    string out = "";
    for (char &c : in) {
        out += encodeOne(c);
    }
    return out;
}*/

string Component::encode(string in) {
    string out = "";
    for (char &c : in) {
        out += encodeOne(c);
    }
    return out;
}
