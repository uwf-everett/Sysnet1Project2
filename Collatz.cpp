//implements functions for Collatz class

#include "Collatz.hpp"

Collatz::Collatz(){
    n = 0;
    steps = 0;
    frequencies = nullptr;
}

//constructor that takes in command line value and generates steps, intializes frequencies array
Collatz::Collatz(int n){
    this->n = n;
    steps = collatzSequence(n);
    frequencies = new int[steps + 1];

    for(int i = 0; i < steps + 1; i++){
        frequencies[i] = 0;
    }
}

//destructor to release frequencies array
Collatz::~Collatz(){
    if(frequencies != nullptr){
        delete[] frequencies;
    }
}

//returns n value
int Collatz::getN(){
    return n;
}

//gives us amount of steps for value given
int Collatz::collatzSequence(int startValue){
    int value = startValue;
    int i = 0;

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

//function for the threads to call might have to research but i think its right
void* Collatz::generateFrequency(void* startValue){
    int i = collatzSequence(*(int*)startValue);

    frequencies[i]++;
}

//here just to test to make sure functions work and produce right values,
//will remove from final project
void Collatz::testFunction(){
    std::cout <<"n = " <<  n << " " << "steps = " << steps << std::endl;
}