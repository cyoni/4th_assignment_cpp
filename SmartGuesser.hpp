#pragma once
#include "Guesser.hpp"
#include <string>
#include <list>
#include <vector>


 using namespace std;

namespace bullpgia{


class SmartGuesser : public bullpgia::Guesser { // son that extends guesser

private:
   
    string guess();
    void learn(string);
    void startNewGame(uint);
 

public:
	SmartGuesser();

};

}
