//
// Created by Andi Koh on 18/10/2016.
//

#ifndef CENIGMA_YSK115_ENCODE_HPP
#define CENIGMA_YSK115_ENCODE_HPP


#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Axle.hpp"

class Encoder {
public:
    Encoder(Plugboard* plugboard, Axle* axle, Reflector* reflector);

    Plugboard* plugboard;
    Reflector* reflector;
    Axle* axle;
    string inputText;
    string currentEncrypt;

    string encode();
protected:
    string readText();
};


#endif //CENIGMA_YSK115_ENCODE_HPP
