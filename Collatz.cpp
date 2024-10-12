//implements functions for Collatz class

#include "Collatz.hpp"

Collatz::Collatz(){
    n = 0;
    t = 0;
    steps = 0;
    frequencies = nullptr;
    stoppingTimes = nullptr;
}

//constructor that takes in command line value and generates steps, intializes frequencies array
Collatz::Collatz(int n, int t){
    nTracker = 1;
    this->n = n;
    this->t = t;
    run();
}

//destructor to release frequencies array
Collatz::~Collatz(){
    if(frequencies != nullptr){
        delete[] frequencies;
    }
    if(stoppingTimes != nullptr){
        delete[] stoppingTimes;
    }
}

//returns n value
int Collatz::getN(){
    return n;
}

int Collatz::safeGetNTracker(){
    // locks access to this function so only one thread can run it at a time
    mtx.lock();
    // makes a temporary int equal to nTracker
    int temp = nTracker;
    // increments nTracker
    nTracker++;
    // unlocks access
    mtx.unlock();
    // returns the temp value 
    return temp;
}

//gives us amount of steps for value given
int Collatz::collatzSequence(int startValue){
    int value = startValue;
    int i = 0;

    if (value == 0){
        return 0;
    }

    while(value != 1){
        if(value % 2 == 0){
            value /= 2;
        }else{
            value = (value * 3) + 1;
        }

        i++;
    }

    return i;
}

void Collatz::run(){
    // initializes array with zeroes
    stoppingTimes = new int[n+1];
    for (int i = 0; i == n; i++){
        stoppingTimes[i] = 0;
    }

    // Makes the threads to generate stopping times
    makeThreads();

    // sets the original to make stopping times
    generateStoppingTimes();

    // joins all threads from the array
    joinThreads();

    // converts the array of stopping times into an array with the frequency of each stopping time
    calculateFrequencies();
    
    std::cout << toString();
    // eventually need time
}

void Collatz::makeThreads(){
    for (int i = 0; i < t; i++){
        // makes t threads that help generate stopping time. Puts them in a vector to be joined later
        myThreads.push_back(std::thread(&Collatz::generateStoppingTimes, this));
    }
    
}

void Collatz::joinThreads(){
    if (t != 0){
        for(int i = 0; i < t; i++){
            myThreads[i].join();
        }
    }
}

void Collatz::generateStoppingTimes(){
    // generates the stopping value for each number 1-n
    while (nTracker <= n){
        // temp is set to the next value from 1-n
        int temp = safeGetNTracker();
        // index[temp] in the array is set to the stopping time of temp
        stoppingTimes[temp] = collatzSequence(temp);
    }
}

void Collatz::calculateFrequencies(){
    max = 0;
    // Finds the highest value in the stopping times table (for some reason the for loop caused a segmentation fault)
    int j = 0;
    while (j < n+1){
        if (stoppingTimes[j] > max){
            max = stoppingTimes[j];
        }
        j++;
    }

    frequencies = new int[max + 1];
    // initializes frequency array values to 0
    for (int i = 0; i <= max; i++){
        frequencies[i] = 0;
    }
    
    // loops through each stopping time and increments its frequency to the frequency array
    for (int i = 1; i <= n; i++){
        frequencies[stoppingTimes[i]]++;
    }
}

std::string Collatz::toString(){
    std::string output = "Frequencies for Collatz values 1-n:\n";
    for (int i = 0; i <= max; i++){
        if (frequencies[i] != 0){
            output += "[" + std::to_string(i) + "]: " + std::to_string(frequencies[i]) + "\n";
        }
    }
    return output;
}