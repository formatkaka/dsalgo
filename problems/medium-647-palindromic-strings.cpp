//
// Created by Siddhant on 2019-11-04.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

bool checkIfPalindrome(string s, int index1, int index2) {

    int start = index1;
    int end = index2;

    cout << "start : " << start << " end : " << end << endl;

    while (start < end) {

        if (s[start] != s[end]) {
            return false;
        }

        start++;
        end--;

    }

    return true;
}

int countSubstrings(string s) {

    int subStrLen = 0, palinSubStrings = 0;

    while (subStrLen <= s.length()) {

        for (int i = 0; i < s.length(); i++) {

            if (i + subStrLen > s.length()) {
                continue;
            }

//            string subStr = s.substr(i, subStrLen);

            bool checkIfPalin = checkIfPalindrome(s, i, i+subStrLen);

            if (checkIfPalin) {
//                cout << "substr palin : " << s << endl;
                palinSubStrings++;
            }

        }

        subStrLen++;

    }

    return palinSubStrings;

}

int main() {

    cout << "check if palindrome : " << countSubstrings("aba");
    return 0;
}