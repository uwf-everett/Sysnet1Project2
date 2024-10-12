#include <iostream>
#include "Collatz.hpp"

int valueBeingComputed = 0;

int main(int argc, char** argv){
    Collatz c = Collatz(100000, 0);

    /*
    //converts command line arguments to ints
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    
    //creates Collatz object
    Collatz c2 = Collatz(n,t);
    //prints values to make sure they are correct
    c2.testFunction();

    //make t amount of threads probably via an array and for loop
    //thread call increment valueBeingComputed so it doesnt work on the same value twice
    //all the way up to n(use the getN function)
    */

    return 0;
}