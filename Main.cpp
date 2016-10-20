// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include "Axle.hpp"

using namespace std;

int main(int argc, char **argv) {
    int numRotors = argc - 2;
    char* pbFilename = argv[numRotors + 1];
    Reflector* reflector = new Reflector();
    Plugboard* plugboard = new Plugboard(pbFilename);
    Rotor** rotors = new Rotor*[numRotors];

    for (int i = 0; i < numRotors; i++) {
         rotors[i] = new Rotor (argv[i+1]);
    }
    Axle* axle = new Axle(numRotors, rotors);

    char in = '\0';
    while (cin >> in) {
        cout << plugboard->encodeOne(axle->encodeOneRL(reflector->encodeOne(axle->encodeOneLR((plugboard->encodeOne(in))))));
    }

    cout << endl;

    return 0;
}

