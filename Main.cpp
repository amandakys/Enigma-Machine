// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "Plugboard.hpp"
#include "Encoder.hpp"
#include "Reflector.hpp"

using namespace std;

/*template <typename T>
T getFirst(unordered_map<T, T> &map, T second);

template <typename T>
T getFirst(unordered_map<T, T> &map, T second) {
    for (auto it = map.begin(); it != map.end(); it++) {
        if ((*it).second == second) {
            return (*it).first;
        }
    }

    return second;
}*/

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

//    Encoder* encoder = new Encoder(plugboard, axle, reflector);
//    string encrypted = encoder->encode();
//
//    cout << encrypted << endl;
    return 0;
}

/*string readText() {
    string in;
    string out = "";
    while (cin) {
        cin >> ws >> in;
        out += in;
        out += " ";
    }
    out.pop_back();
    size_t last = out.find_last_of(" ");
    out = out.substr(0, last);
    return out;
}
  unordered_map<char, char> map;

    map.insert(make_pair<char, char>('a', 'b'));
    map.insert(make_pair<char, char>('c', 'd'));

    cout << getFirst(map, 'd') << endl;
*/
