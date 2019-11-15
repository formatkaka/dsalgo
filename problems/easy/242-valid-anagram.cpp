//
// Created by Siddhant on 2019-11-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

string getHash(string &s) {

    vector<int> freq(26, 0);
    string res = "";

    for (int i = 0; i < s.length(); ++i) {
        freq[s[i] - 'a']++;
    }

    for (int j = 0; j < freq.size(); ++j) {
        res = res + to_string(freq[j]) + "#";
    }

    return res;

}

bool isAnagram(string s, string t) {
    return getHash(s) == getHash(t);
}

int main() {

    string s = "anagram", t = "nagaram";
    isAnagram(s, t);
    return 0;
}