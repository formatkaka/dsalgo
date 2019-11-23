//
// Created by Siddhant on 2019-08-29.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    string J = "aA";
    string S = "aAAbbb";
    int typeOfJewels = 0;
    for (const auto &j : J) {
        for (const auto &s : S) {
            if(j == s){
                typeOfJewels++;
            }
        }
    }

    std::cout << "typeOfJewels : " << typeOfJewels;

    return 0;
}