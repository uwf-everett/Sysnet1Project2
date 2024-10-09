//Class containing logic for Collatz sequences

#ifndef COLLATZ_HPP
#define COLLATZ_HPP

#include <iostream> //remove when we get rid of test function

class Collatz{
    private:
        int n;
        int steps;
        int* frequencies; //will contain an array of step values
        int collatzSequence(int startValue);
    public:
        Collatz();
        Collatz(int n);
        ~Collatz();
        int getN();
        void* generateFrequency(void* startValue);
        void testFunction();
};

#endif