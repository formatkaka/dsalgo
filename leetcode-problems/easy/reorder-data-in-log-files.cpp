//
// Created by Siddhant on 2019-11-19.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<string> sentenceToWordVec(string sentence) {

    string word = "";
    vector<string> res;

    int j = 0;
    string first_word = "";
    for (j = 0; j < sentence.length() - 1; ++j) {
        if (sentence[j] == ' ') {
            first_word = word;
            word = "";
            break;
        }
    }

    for (int i = j + 1; i < sentence.length() - 1; ++i) {

        if (sentence[i] == ' ') {
            res.push_back(word);
            word = "";
            continue;
        }

        word += sentence[i];

    }

    if (!word.empty()) {
        res.push_back(word);
    }

    res.push_back(first_word);

    return res;

}

bool strcompare(vector<string> str1, vector<string> str2, int index) {

    return str1[index] > str2[index];

}

vector<string> reorderLogFiles(vector<string> &logs) {

    vector<vector<string>> wordss(logs.size());

    for (int i = 0; i < logs.size(); ++i) {
        wordss.push_back(sentenceToWordVec(logs[i]));
    }

    int i = 0;

    while () {

        sort(wordss.begin(), wordss.end(), [](const auto &lhs, const auto &rhs) {
            return lhs[i] < rhs.first;
        });

    }

}

int main() {


    return 0;
}