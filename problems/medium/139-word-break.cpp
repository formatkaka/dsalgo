//
// Created by Siddhant on 2019-11-11.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

unordered_map<string, bool> map;

bool wordBreak(string s, vector<string> &wordDict) {


    if (s.empty()) {
        return true;
    }

    if(map.find(s) != map.end()){
        cout << "using cache : " << s << endl;
        return map[s];
    }

    bool got = false;
    for (int i = 0; i < wordDict.size(); i++) {

        int find = s.find(wordDict[i]);

        if ( find != string::npos) {
            string sub1 = s.substr(0, find);
            string sub2 = s.substr(find+wordDict[i].length());

//            cout << "s : " << s << " dict : " << wordDict[i] << " sub1 : " << sub1 << " sub2 : " << sub2 << endl;
            got = got || (wordBreak(sub1, wordDict) && wordBreak(sub2, wordDict));
        }

    }

    map.insert(make_pair(s, got));

    return got;

}

int main() {
    string s = "catsandog";
    vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    cout << "break : " << endl << wordBreak(s, dict);
    return 0;
}