
#include <iostream>
#include <string>
using std::string;
#include "calculate.hpp"


std::string calculateBullAndPgia(const std::string str1, const std::string str2){

    int len1 = str1.length();
    int len2 = str2.length();
    int arr1[len1];
    int arr2[len2];
    int visited[len2];
    for (int i=0; i<len1; i++) visited[i] = 0;

    if (len1 != len2) std::cout << "error!!" << std::endl;

    for (int i=0; i<len1; i++){arr1[i] = str1[i];arr2[i] = str2[i];} // copy strings into arrays

    int B=0;
    int P=0;

    for (int i=0; i<len1; i++){//o(n^2)
    if (visited[i] == 1) continue;

    if (arr1[i] == arr2[i]){
    visited[i]=-1;
    B++;
    }
    else{
        for (int j=0; j<len1; j++){
        if (i!=j && arr1[i] == arr2[j] && visited[j] == 0 ){
        P++;
        visited[j]=-1;
        }
    }

    }

    }
   // std::cout << "b=" << B << " p=" << P << " str1=" << str1 << ", str2=" << str2 << std::endl;
    std::string result = std::to_string(B) + "," + std::to_string(P);
    return result;
}
