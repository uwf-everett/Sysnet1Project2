//Class containing logic for Collatz sequences

#ifndef COLLATZ_HPP
#define COLLATZ_HPP

#include <iostream> //remove when we get rid of test function
#include <mutex>
#include <thread>
#include <string>
#include <vector>

class Collatz{
    private:
        int n; // number to reach
        int t; // number of threads
        int max; // maximum value found for stopping time (used in toString and calculateFrequencies)
        int nTracker; // Keeps track of what point from 1-n we are at
        int steps;
        int* stoppingTimes;
        int* frequencies; //will contain an array of step values
        std::mutex mtx;
        //std::thread* myThreads;
        std::vector<std::thread> myThreads;
        int collatzSequence(int startValue);
        int safeGetNTracker(); // Uses a mutex to safely get the next nTracker value.
        void makeThreads();
        void joinThreads();
        //void generateStoppingTimes(); // generates all stopping times
        void calculateFrequencies(); // fills the frequency array
        std::string toString();
    public:
        Collatz();
        Collatz(int n, int t);
        ~Collatz();
        int getN();
        //void* generateFrequency(void* startValue);
        void testFunction();
        void run();
        void generateStoppingTimes(); // generates all stopping times
};

#endif