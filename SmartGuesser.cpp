
#include "SmartGuesser.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

    using namespace std;
    bullpgia::SmartGuesser::SmartGuesser(){
    }

    void bullpgia::SmartGuesser::learn(string str){
    bAndp = str;
    }

    void bullpgia::SmartGuesser::startNewGame(uint l){
    bul=-1;
    looking=0;
    dig_Counter=9;
    
    length=l;
    Guess="";
    found=0;
    Try=0;
    not_in_place.resize(length);
    not_in_place.clear();
    certain.resize(length);  // the array that we keep the numbers we certainly know in the right place of the seq.
    for (int i=0; i<length; i++) certain[i] = -1;

    }

    string bullpgia::SmartGuesser::give_sequence(){
    Guess="";
    for (int i=0; i<length; i++){
        Guess = Guess + to_string(dig_Counter);
    }
    dig_Counter--;
    return Guess;
    }

    bool bullpgia::SmartGuesser::check_if_not_in_list (int index, int digit){
    for (std::list<int>::iterator it = not_in_place[index].begin(); it != not_in_place[index].end(); it++){ 
	    // check if the number is in on of the lists
    if (*it == digit) return true; // the number was found
	}
    return false; // the number was not found
    }
    string bullpgia::SmartGuesser::guess(){ // goes to here
    string tmp1 = "";
    string tmp2 = "";
        Try++;
        for (int i=0; i<bAndp.length(); i++){ // split the string
        if (bAndp[i] == ','){
        for (int j=i+1; j<bAndp.length(); j++) tmp2+=bAndp[j];
        break;
        }
        else  tmp1+=bAndp[i];
        }
         bul = atoi(tmp1.c_str());
        if ((Try == 1) || (Try == 2 && bul-found>0)){ // new game. 1st try -- choose a sequence and send it
            Try=1;
            return give_sequence();
                }
            if (bul-found==1){
            certain[looking++] = 0;
            found++;
           
                }
              if (bul-found==0){
              for (int i=0; i<length; i++){

             if (!check_if_not_in_list(i, Guess[i]-48)){not_in_place[i].push_back(Guess[i]-48);};
                        }
                    }
            int Rand = 0;
            if (certain[looking] == -1){ // lets find i.
                while(1){
                 Rand = rand() % 10;
                if (check_if_not_in_list(looking, Rand)==0){ // if the random number was not picked up before
                Guess[looking] = Rand+48;
                return Guess;}
                    }
                }
    return Guess;
    }
