//
// Created by Siddhant on 2019-08-27.
//

#include "iostream"
#include "string"

using namespace std;


int main(){

    string mystring = "255.100.50.0";
    string output = "";
    for (auto itr = mystring.begin(); itr < mystring.end(); ++itr) {
        if(*itr == '.'){
            output = output + "[.]";
        }else{
            output = output + (*itr);
        }
    }

    std::cout << "Output : " << output << std::endl;

}