#pragma once
#include "Guesser.hpp"
#include <string>
#include <list>
#include <vector>


 using namespace std;

namespace bullpgia{


class SmartGuesser : public bullpgia::Guesser { // son that extends guesser

private:
    int dig_Counter;
 
    int bul;
    int looking;
    int found;

    bool check_if_not_in_list(int,int);
    vector<list<int>> not_in_place;
    vector<int>certain;
    string bAndp;
    string guess();
    string give_sequence();
    void learn(string);
    void startNewGame(uint);
    int Try;

    string Guess;




protected: // can be accessed only by base members, friends and derived classes


public:
	SmartGuesser();

};

}

