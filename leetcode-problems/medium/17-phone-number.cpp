//
// Created by Siddhant on 2019-11-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<string> map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

vector<string> letterCombinations(string digits) {
    vector<string> s;
    vector<string> old;

    for (int i = 0; i < digits.size(); i++) {
        int digit = digits[i] - '0';

        if (s.empty()) {

            for (int j = 0; j < map[digit].size(); j++) {
                string character(1,map[digit][j]);
                s.push_back(character);
            }

            old = s;
            continue;
        }

        s = {};

        for (int j = 0; j < map[digit].size(); j++) {

            for (int k = 0; k < old.size(); k++) {
                s.push_back(old[k] + map[digit][j]);
            }

        }
            old = s;

    }

    return s;

}

int main() {

    letterCombinations("23");
    cout << "hello";
    return 0;
}