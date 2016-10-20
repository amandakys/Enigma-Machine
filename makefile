# edit this makefile so that running make compiles your enigma program

enigma: Main.o Plugboard.o Component.o Encoder.o Reflector.o Axle.o Rotor.o
	g++ -g -std=c++11 -o enigma Main.o Plugboard.o Component.o Encoder.o Reflector.o Axle.o Rotor.o

Main.o: Main.cpp
	g++ -g -std=c++11 -c Main.cpp -o Main.o

Plugboard.o: Plugboard.cpp
	g++ -g -std=c++11 -c Plugboard.cpp -o Plugboard.o

Component.o: Component.cpp
	g++ -g -std=c++11 -c Component.cpp -o Component.o

Encoder.o: Encoder.cpp
	g++ -g -std=c++11 -c Encoder.cpp -o Encoder.o

Reflector.o: Reflector.cpp
	g++ -g -std=c++11 -c Reflector.cpp -o Reflector.o

Axle.o: Axle.cpp
	g++ -g -std=c++11 -c Axle.cpp -o Axle.o

Rotor.o: Rotor.cpp
	g++ -g -std=c++11 -c Rotor.cpp -o Rotor.o

clean:
	rm -rf enigma *.o

.PHONY: clean
