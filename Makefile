main: main.o Collatz.o
	g++ -g -Wall main.o Collatz.o -o main

main.o: mt-collatz.cpp
	g++ -g -Wall -c mt-collatz.cpp -o main.o

Collatz.o: Collatz.hpp Collatz.cpp
	g++ -g -Wall -c Collatz.hpp Collatz.cpp

clean:
	rm *.o *.gch main