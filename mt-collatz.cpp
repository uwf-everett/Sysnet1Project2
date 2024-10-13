#include <iostream>
#include "Collatz.hpp"

int valueBeingComputed = 0;

int main(int argc, char** argv){
    //converts command line arguments to ints
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    
    //creates aand runs Collatz object
    Collatz c2 = Collatz(n,t);

    return 0;
}