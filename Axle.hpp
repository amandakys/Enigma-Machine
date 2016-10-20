//
// Created by Andi Koh on 19/10/2016.
//

#ifndef CENIGMA_YSK115_AXLE_HPP
#define CENIGMA_YSK115_AXLE_HPP


#include "Rotor.hpp"

class Axle: public Component {
public:
    Axle(int numRotors, Rotor** rotors);
    Rotor** rotors;
    void rotateRotors();
private:
    virtual char encodeOne(char in);
    int numRotors;
};


#endif //CENIGMA_YSK115_AXLE_HPP
