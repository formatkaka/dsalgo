//
// Created by Siddhant on 2019-11-17.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int find(string &s, int i,  vector<int>& memo) {

    if (i <= 0) {
        return 1;
    }

    int l1 = 0, l2 = 0;

    if(memo[i] != -1){
        return memo[i];
    }

    if (s[i] != '0') {
        l1 = find(s, i - 1, memo);
    }

    if (i > 0) {

        int n = stoi(s.substr(i - 1, 2));
        if (n >= 10 && n <= 26) {
            l2 = find(s, i - 2, memo) ;
        }

    }

    memo[i] = l1 + l2;

    return l1 + l2;

}

int numDecodings(string s) {
    if (s.empty()) return 0;
    vector<int> memo(s.length(), -1);
    return find(s, s.length() - 1, memo);
}

int main() {

    cout << numDecodings("10");
    return 0;
}