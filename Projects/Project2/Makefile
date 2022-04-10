# Makefile

Airplane: AirportDriver.o Airplane.o
	g++ -Wall -pedantic -g -o Airplane AirportDriver.o Airplane.o

Airplane.o: Airplane.cpp Airplane.h 
	g++ -Wall -pedantic -g -std=c++11 -c Airplane.cpp

AirportDriver.o: AirportDriver.cpp Airplane.h
	g++ -Wall -pedantic -g -std=c++11 -c AirportDriver.cpp

clean:
	rm -f Airplane Airplane.exe Airplane.
	