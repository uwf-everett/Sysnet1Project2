#include <iostream>
#include "Collatz.hpp"

int main(int argc, char** argv){
    //converts command line arguments to ints
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    
    //creates Collatz object
    Collatz c = Collatz(n);

    return 0;
}