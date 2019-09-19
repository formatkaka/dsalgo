//
// Created by Siddhant on 2019-09-19.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<int> diStringMatch(string S){
    int len = S.size();
    vector<int> result;
    int start = 0;
    int end = len;

    for (int i = 0; i < len; ++i) {
        switch(S[i]) {
            case 'I':
                result.push_back(start++);
                break;
            case 'D':
                result.push_back(end--);
                break;
        }

    }

    result.push_back(end);

    return result;
}

int main(){

    string S = "I";
    vector<int> output = diStringMatch(S);

    for (int i = 0; i < output.size(); ++i) {
        cout << " i " << i << " " << output[i] << endl;
    }

    return 0;
}