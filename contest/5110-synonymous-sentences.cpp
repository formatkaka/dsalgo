//
// Created by Siddhant on 2019-11-16.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"

using namespace std;

vector<string> generateSentences(vector<vector<string>> &synonyms, string text) {

    vector<vector<string>> dict;
    unordered_map<string, int> map;

    for (int i = 0; i < synonyms.size(); i++) {

        if (dict.empty()) {
            dict.push_back(synonyms[i]);
            map[synonyms[i][0]] = dict.size() - 1;
            map[synonyms[i][1]] = dict.size() - 1;
            continue;
        }

        auto s0 = map.find(synonyms[i][0]);
        auto s1 = map.find(synonyms[i][1]);

        if (s0 == map.end() && s1 == map.end()) {
            dict.push_back(synonyms[i]);
            map[synonyms[i][0]] = dict.size() - 1;
            map[synonyms[i][1]] = dict.size() - 1;
            continue;
        }

        if (s0 != map.end() && s1 != map.end()) {
            continue;
        }

        if (s0 != map.end()) {
            int index = map[synonyms[i][0]];
            dict[index].push_back(synonyms[i][1]);
            map[synonyms[i][1]] = index;
            continue;
        }

        if (s1 != map.end()) {
            int index = map[synonyms[i][1]];
            dict[index].push_back(synonyms[i][0]);
            map[synonyms[i][0]] = index;
        }

    }

    for (int j = 0; j < dict.size(); ++j) {
        sort(dict[j].begin(), dict[j].end());
    }

    unordered_map<string, vector<string>> m;

    for (int l = 0; l < dict.size(); ++l) {

        for (int i = 0; i < dict[l].size(); ++i) {

            m.insert(make_pair(dict[l][i], dict[l]));

        }

    }

    vector<string> result;

//    for (int k = 0; k < text.size(); ++k) {
//
//        string word = "";
//
//        while(text[k] != ' '){
//
//            word += text[k++];
//
//        }
//
//        if(m.find(word) != m.end()){
//
//            for (int j = 0; j < result.size(); ++j) {
//
//            }
//
//            for (int i = 0; i < m[word].size(); ++i) {
//
//            }
//
//        }
//
//    }

}

int main() {

    vector<vector<string>> synonyms = {{"happy", "joy"},
                                       {"sad",   "sorrow"},
                                       {"joy",   "cheerful"}};
    string text = "I am happy today but was sad yesterday";
    generateSentences(synonyms, text);
    return 0;
}