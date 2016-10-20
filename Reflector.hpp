//
// Created by Andi Koh on 19/10/2016.
//

#ifndef CENIGMA_YSK115_REFLECTOR_HPP
#define CENIGMA_YSK115_REFLECTOR_HPP


#include "Component.hpp"

class Reflector : public Component {
public:
    virtual char encodeOne(char in);
};


#endif //CENIGMA_YSK115_REFLECTOR_HPP
