#include <iostream>
#include "Collatz.hpp"

int valueBeingComputed = 0;

int main(int argc, char** argv){
    //converts command line arguments to ints
    int n = atoi(argv[1]);
    int t = atoi(argv[2]);
    
    //creates Collatz object
    Collatz c2 = Collatz(n,t);

    return 0;
}

// CODING TO-DO:
// need to do sterr or something for running time instead of what I did
// need [-nolock]
// need a way to write to a file
// can't compute n values larger than 100,000


// NON-CODING TO-DO:
// description of experiment
// visualized histogram of stopping times
// results from experiments including a graph comparing threads vs runtime with and without locks
// analysis of performance improvements through parallel execution
// analysis on impact of locks on performance
    // I already know this greatly lowers performance
// conclusions from experiments