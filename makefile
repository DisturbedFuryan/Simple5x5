CC=g++
CFLAGS=-c -Wall


all: Simple5x5

Simple5x5: main.o FiveTimesFive.o
	$(CC) main.o FiveTimesFive.o -o Simple5x5

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

FiveTimesFive.o: FiveTimesFive.cpp
	$(CC) $(CFLAGS) FiveTimesFive.cpp

clean:
	rm -rf *.o Simple5x5
