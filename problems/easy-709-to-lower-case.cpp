//
// Created by Siddhant on 2019-08-29.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    string input = "LOVELY";
    string output = "";
    for (auto wrapIter = input.begin(); wrapIter != input.end(); ++wrapIter) {
        bool isCaps = *wrapIter >= 65 && *wrapIter <= 90;

        if(isCaps){
            char small = *wrapIter + 32;
            output = output + small;
        }else{
            output = output + *wrapIter;
        }

    }

    cout << "Output : " << output;

    return 0;
}