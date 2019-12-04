//
// Created by Siddhant on 2019-12-02.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"
#include "unordered_map"

using namespace std;

unordered_set<string> dict;
unordered_map<int, vector<string>> m;

vector<string> find(string& s, int startIndex){

    vector<string> sentences;

    if(startIndex >= s.length()){
        return sentences;
    }

    if(m.find(startIndex) != m.end()){
        cout << "using";
        return m[startIndex];
    }

    for (auto dictWord = dict.begin(); dictWord != dict.end(); ++dictWord) {

        string sub = s.substr(startIndex, (*dictWord).length());

        if(sub == *dictWord){
            int endIndex = startIndex+(*dictWord).length();

            if(endIndex <= s.length()-1) {
                vector<string> subsentences = find(s, startIndex + (*dictWord).length());

                for (int i = 0; i < subsentences.size(); ++i) {

                    sentences.push_back(sub + " " + subsentences[i]);

                }
            }else{
                sentences.push_back(sub);
            }

        }

    }

    m[startIndex] = sentences;

    return sentences;

}

vector<string> wordBreak(string s, vector<string> &wordDict) {

    for (int i = 0; i < wordDict.size(); ++i) {
        dict.insert(wordDict[i]);
    }

    vector<string> sentences = find(s, 0);
    return sentences;

}

int main() {

    vector<string> wordDict = {"a", "b"};
    string s = "ab";
    wordBreak(s, wordDict);
    return 0;
}