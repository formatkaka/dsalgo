//
// Created by Siddhant on 2019-11-03.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

unordered_map<string, int> map;

int longestCommonSubsequence(string text1, string text2) {

    if(text1.empty() || text2.empty()){
        return 0;
    }

    if(map.find(text1+text2) != map.end()){
        cout << "common found : " << text1+text2 << endl;
        return map[text1+text2];
    }

    char currChar = text1[0];
    string followUpT1 = text1.substr(1, text1.length());

    int findCurrCharInT2 = text2.find(currChar);

    int maxLCSWithChar = INT_MIN;

    if(findCurrCharInT2 != string::npos){
        cout << "found curr char " << currChar << " at : " << findCurrCharInT2 << " " << text2[findCurrCharInT2] << endl;
        string followUpT2 = text2.substr(findCurrCharInT2, text2.length());
        maxLCSWithChar = 1 + longestCommonSubsequence(followUpT1, followUpT2);
    }

    int maxLCSWithoutChar = longestCommonSubsequence(followUpT1, text2);

    int maxLCS = max(maxLCSWithChar, maxLCSWithoutChar);

    map.insert(make_pair(text1+text2, maxLCS));

    return maxLCS;

}

int main(){

    string s1 = "abcde";
    string s2 = "jmjkbkjkv";
    cout << longestCommonSubsequence(s1, s2);
    return 0;
}