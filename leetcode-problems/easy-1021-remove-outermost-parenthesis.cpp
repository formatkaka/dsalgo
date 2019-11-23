//
// Created by Siddhant on 2019-08-29.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    string S = "()()";
    string output = "";
    int closureIndex = 0, startIndex = 0, endIndex = 0, i = 0;
    for (auto str = S.begin(); str != S.end(); ++str, ++i) {

        if(*str == '('){
            closureIndex += 1;
        }else{
            closureIndex -= 1;
        }

        if(closureIndex == 0){
            endIndex = i;

//            cout << "Started here : " << startIndex << std::endl;
//            cout << "End here : " << endIndex << std::endl;
//            cout << "Substr : " << S.substr(startIndex + 1, endIndex - startIndex - 1) << std::endl << endl;
            output = output + S.substr(startIndex + 1,  endIndex - startIndex - 1);

            startIndex = i+1;
        }
    }

    cout << "Output : " << output;

    return 0;
}