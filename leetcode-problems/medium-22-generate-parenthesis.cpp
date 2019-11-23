//
// Created by Siddhant on 2019-11-05.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<string> result;

void generateParenthesis_rec(string curr,int openBr, int closeBr) {


    if(openBr == 0 && closeBr == 0){
        result.push_back(curr);
        return;
    }

    if(openBr == closeBr){
        generateParenthesis_rec(curr+'(', openBr-1, closeBr);
        return;
    }

    if(openBr == 0){
        generateParenthesis_rec(curr+')', openBr, closeBr-1);
        return;
    }

    generateParenthesis_rec(curr+'(', openBr-1, closeBr);
    generateParenthesis_rec(curr+')', openBr, closeBr-1);
}

vector<string> generateParenthesis(int n) {

    generateParenthesis_rec("", n, n);
    return result;
}

int main(){

    generateParenthesis(13);

    for (auto str = result.begin(); str != result.end(); ++str) {
        cout << (*str) << endl;
    }

    return 0;
}