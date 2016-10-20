//
// Created by Andi Koh on 19/10/2016.
//

#ifndef CENIGMA_YSK115_ROTOR_HPP
#define CENIGMA_YSK115_ROTOR_HPP


#include <string>
#include "Component.hpp"

class Rotor : public Component {
public:
    Rotor();

    Rotor(string filename);
    void rotate();
    void resetRotations();
    int getRotations();
    virtual char encodeOne(char in);
private:
    int numRotations;
    string filename;
    int* values;
    void readfile();

};


#endif //CENIGMA_YSK115_ROTOR_HPP
