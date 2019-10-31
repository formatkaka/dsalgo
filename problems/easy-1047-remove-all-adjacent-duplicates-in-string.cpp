//
// Created by Siddhant on 2019-10-18.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

//string removeDuplicates(string S) {
//
//    if(S.length() < 2) return S;
//    int len;
//    for (int i = 0;len = S.length(), i < len - 1; ++i) {
//
//        if(S[i] == S[i+1]){
//            S.erase(i, 2);
//            i = i>=1 ? i-2 : -1;
//        }
//    }
//
//    return S;
//
//}

string removeDuplicates(string S) {

    string res = "0";

    for (int i = 0; i < S.length(); ++i) {

        if(res.back() == S[i]){
            res.pop_back();
        }else{
            res.push_back(S[i]);
        }

    }

    return res.substr(1);

}

int main(){

    string S = "acca";
    cout << "ans is : " << removeDuplicates(S);
    return 0;
}