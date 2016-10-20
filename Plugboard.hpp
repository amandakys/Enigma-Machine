//
// Created by Andi Koh on 15/10/2016.
//

#ifndef CENIGMA_YSK115_PLUGBOARD_HPP
#define CENIGMA_YSK115_PLUGBOARD_HPP


#include <cstdio>
#include <fstream>
#include <map>
#include "Component.hpp"

using namespace std;

class Plugboard : public Component {
public:
    Plugboard(string filename);
    Plugboard();
    void printValues();
    int* values;

    virtual char encodeOne(char in);

protected:
    string filename;
    int numValues;
    map<int, int> valueMap;
    void readfile();
    void generateMap();
};


#endif //CENIGMA_YSK115_PLUGBOARD_HPP
