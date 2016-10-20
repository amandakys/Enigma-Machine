# edit this makefile so that running make compiles your enigma program

CC = g++
FLAGS = -std=c++11

enigma: Main.o Plugboard.o Component.o Reflector.o Axle.o Rotor.o
	$(CC) $(FLAGS) -o $@ $^

Main.o: Main.cpp
	$(CC) $(FLAGS) -c $^ -o $@

Plugboard.o: Plugboard.cpp
	$(CC) $(FLAGS) -c $^ -o $@

Component.o: Component.cpp
	$(CC) $(FLAGS) -c $^ -o $@

Reflector.o: Reflector.cpp
	$(CC) $(FLAGS) -c $^ -o $@

Axle.o: Axle.cpp
	$(CC) $(FLAGS) -c $^ -o $@

Rotor.o: Rotor.cpp
	$(CC) $(FLAGS) -c $^ -o $@

clean:
	rm -rf enigma *.o

.PHONY: clean
