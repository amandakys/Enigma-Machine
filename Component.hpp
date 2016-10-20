//
// Created by Andi Koh on 16/10/2016.
//

#ifndef CENIGMA_YSK115_COMPONENT_HPP
#define CENIGMA_YSK115_COMPONENT_HPP


#include <map>

using namespace std;
class Component {
public:
    Component();
protected:
    std::map<int, char> intCharMap;
    char intToChar(int i);
    int charToInt(char c);
    void generateIntCharMap();
    virtual char encodeOne(char in);

};


#endif //CENIGMA_YSK115_COMPONENT_HPP
