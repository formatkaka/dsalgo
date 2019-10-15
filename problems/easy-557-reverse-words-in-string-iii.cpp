//
// Created by Siddhant on 2019-10-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

string reverseWords1(string s) {

    string revWord = "";
    string finalString = "";
    for (int i = s.size() - 1; i >= 0; --i) {

        if (s[i] == ' ') {
            if (finalString.length() > 0) { revWord = revWord + ' '; }
            finalString = revWord + finalString;
            revWord = "";
            continue;
        }

        revWord += s[i];
    }

    if (finalString.length() > 0) { revWord = revWord + ' '; }
    finalString = revWord + finalString;
    return finalString;
}

string reverseWordsOptimised(string s){

    int start = 0;

    for (int i = 0; i <= s.size(); ++i) {

        if(i == s.length() || s[i] == ' '){
            reverse(begin(s)+start, begin(s)+i);
            start = i+1;
        }
    }

    return s;
    
}

int main() {

    cout << "reversed string is : " << reverseWordsOptimised("lets take leetcode cxontat");
    return 0;
}