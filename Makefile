CC=g++
CFLAGS= -g -Wall -Werror -std=c++17 -pedantic
LIBS68 = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: NBody

NBody: main.o CelestialBody.o Universe.o
	$(CC) $(CFLAGS) -o NBody main.o CelestialBody.o Universe.o $(LIBS68)

main.o: main.cpp CelestialBody.hpp Universe.hpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

CelestialBody.o: CelestialBody.cpp CelestialBody.hpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp -o CelestialBody.o

Universe.o: Universe.cpp Universe.hpp
	$(CC) $(CFLAGS) -c Universe.cpp -o Universe.o

clean:
	rm *.o NBody


