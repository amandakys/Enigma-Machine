//
// Created by Andi Koh on 18/10/2016.
//

#include <iostream>
#include "Encoder.hpp"

using namespace std;

Encoder::Encoder(Plugboard* plugboard, Axle* axle, Reflector* reflector){
    this->plugboard = plugboard;
    this->axle = axle;
    this->reflector = reflector;
    this->inputText = readText();
}

string Encoder::readText() {
    string in;
    string out = "";
    while (!cin.eof()) {
        cin >> ws >> in;
        out += in;
        //out += " ";
    }
    // out.pop_back();
    // size_t last = out.find_last_of(" ");
    out = out.substr(0, out.length() - in.length());
    return out;
}

string Encoder::encode() {
    string out;
    for (char& c : inputText) {
//        cout << plugboard->encodeOne(c) << endl;
//        cout << axle->encodeOneLR((plugboard->encodeOne(c))) << endl;
//        cout << reflector->encodeOne(axle->encodeOneLR((plugboard->encodeOne(c)))) << endl;
        out += plugboard->encodeOne(axle->encodeOneRL(reflector->encodeOne(axle->encodeOneLR((plugboard->encodeOne(c))))));
    }

    return out;
}
