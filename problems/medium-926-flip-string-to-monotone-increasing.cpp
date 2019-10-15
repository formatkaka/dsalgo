//
// Created by Siddhant on 2019-10-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

//string getValidStr(int len, int index){
//    return string(index, '0') + string(len-index, '1');
//}

//int returnStringDiff(string str1, string str2){
//    int diff = 0;
//    for (int i = 0; i < str1.length(); ++i) {
//        if(str1[i] != str2[i]){
//            diff++;
//        }
//    }
//
//    return diff;
//
//}

//int minFlipsMonoIncr(string S) {
//
//    int minFlips = INT_MAX;
//
//    for (int i = 0; i <= S.length(); ++i) {
//
//        string validStr = getValidStr(S.length(), i);
//        int diff = returnStringDiff(S, validStr);
//        if(diff < minFlips){
//            minFlips = diff;
//        }
//    }
//
//    return minFlips;
//
//}

// v2

int getInitialDiff(string S){

    int minFlips = 0;

    for (int i = 0; i < S.length(); ++i) {
        if(S[i] != '1'){
            minFlips++;
        }
    }

    return minFlips;

}

int minFlipsMonoIncr(string S){

    int minFlips = getInitialDiff(S);
    int currDiff = minFlips;
    for (int i = 0; i < S.length(); ++i) {

        if(S[i]=='0'){
            currDiff -= 1;
        }else{
            currDiff += 1;
        }

        if(currDiff < minFlips){
            minFlips = currDiff;
        }

    }

    return minFlips;

}

int main(){

    string S = "00011000";
//    cout << string(7, '*')
    cout << "Ans : " << minFlipsMonoIncr(S);

    return 0;
}
