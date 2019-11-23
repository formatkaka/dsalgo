//
// Created by Siddhant on 2019-11-20.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

void alienToHuman(string &s, unordered_map<char, char> &alienHumanMap) {

    for (int i = 0; i < s.length(); ++i) {

        s[i] = alienHumanMap[s[i]];

    }

}

bool isAlienSorted(vector<string> &words, string order) {

    unordered_map<char, char> alienHumanMap;
    char human = 'a';
    for (int i = 0; i < order.length(); i++) {

        alienHumanMap.insert(make_pair(order[i], human));
        human++;
    }

    string prevword;

    for (int j = 0; j < words.size(); ++j) {

        if(prevword.empty()){
            prevword = words[j];
            alienToHuman(prevword, alienHumanMap);
            continue;
        }

        string s = words[j];
        alienToHuman(s, alienHumanMap);

        if(s < prevword){
            return false;
        }

        prevword = s;

        cout << s << endl;

    }

    return true;
}

int main() {
    vector<string> words = {"apple","app"};
    string order = "abcdefghijklmnopqrstuvwxyz";
    cout << isAlienSorted(words, order);
    return 0;
}