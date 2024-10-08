//Class containing logic for Collatz sequences

#ifndef COLLATZ_HPP
#define COLLATZ_HPP

class Collatz{
    private:
        int n;
        int steps;
        int* frequencies; //will contain an array of step values
    public:
        Collatz();
        Collatz(int n);
};

#endif