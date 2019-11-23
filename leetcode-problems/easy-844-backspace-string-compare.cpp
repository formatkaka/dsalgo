//
// Created by Siddhant on 2019-10-31.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool backspaceCompare(string S, string T) {

    string outputS, outputT;
    char BACKSPACE = '#';
    for (int i = 0; i < S.length(); ++i) {


        if(S[i] == BACKSPACE && !outputS.empty()){
            outputS = outputS.substr(0,outputS.length()-1);
        }

        if(S[i] != BACKSPACE){
            outputS += S[i];
        }
    }

    for (int i = 0; i < T.length(); ++i) {


        if(T[i] == BACKSPACE && !outputT.empty()){
            outputT = outputT.substr(0,outputT.length()-1);
        }

        if(T[i] != BACKSPACE){
            outputT += T[i];
        }
    }

    cout << "output S : " << outputS << endl;
    cout << "output T : " << outputT << endl;

    return outputS == outputT;

}

int main(){

    string str1 = "xywrrmp";
    string str2 = "xywrrmu#p";
    cout << "is similar : " << backspaceCompare(str1, str2);
    return 0;
}