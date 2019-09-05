//
// Created by Siddhant on 2019-09-05.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;

int main(){

    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> output;

    for (auto word = words.begin(); word != words.end(); ++word) {

        unordered_map<char, char> wordPatternMap;
        unordered_set<char> patternCharAdded;
        int index = 0;
        string mappedOutput = "";

        cout << "word : " << (*word) << endl;

        for (auto character = (*word).begin(); character != (*word).end(); ++character, index++) {

            bool mappingAlreadyExists = wordPatternMap.find(*character) != wordPatternMap.end();
            bool patternCharAlreadyMapped = patternCharAdded.find(pattern[index]) != patternCharAdded.end();

            if(mappingAlreadyExists){
                mappedOutput += wordPatternMap.find(*character)->second;
            }

            if(!mappingAlreadyExists && patternCharAlreadyMapped){
                break;
            }

            if(!mappingAlreadyExists && !patternCharAlreadyMapped){
                wordPatternMap.insert(make_pair(*character, pattern[index]));
                patternCharAdded.insert(pattern[index]);
                mappedOutput += pattern[index];
            }

        }

        int result = mappedOutput.compare(pattern);

        if(result == 0){
            output.push_back(*word);
        }
    }


    return 0;
}