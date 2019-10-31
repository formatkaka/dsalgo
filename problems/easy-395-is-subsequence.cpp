//
// Created by Siddhant on 2019-10-17.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool isSubsequence(string s, string t) {

    int j = 0;

    for (int i = 0; i < t.length(); ++i) {
        if(t[i] == s[j]){
            j++;
        }
    }

    return j == s.length();

}

int main(){

    cout << "is subsequence : " << isSubsequence("abc", "ahbgdc");
    return 0;
}