#pragma once

#include <iostream>

#include "calculate.hpp"

using std::string;

// the player who guesses the string
namespace bullpgia{

    class Guesser{ // father
    public:

    Guesser(){}
    uint length;


    virtual	std::string guess()=0; // pure virtual function no one reads it - we do not implement this. Classes override this

    virtual void learn(std::string str){}; // cant be pure virtual-no one overrides this. if some one overrides this, I can make it pure virtual.
    //but if not, then I have to implement it.

    virtual void startNewGame(uint len){ // if it is virtual start() in the son will be invoked
    length = len;
   }

};

}
