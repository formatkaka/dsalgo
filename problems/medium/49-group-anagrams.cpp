//
// Created by Siddhant on 2019-11-13.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

// PREVIOUS

//
//void addStrToVec(vector<unordered_map<char, vector<int>>> &strLenMap, string &s) {
//
//    unordered_map<char, vector<int>> charFrequencyMap;
//
//    for (int i = 0; i < s.length(); ++i) {
//
//        if (charFrequencyMap.find(s[i]) == charFrequencyMap.end()) {
//            vector<int> v = {0, 0};
//            charFrequencyMap[s[i]] = v;
//        }
//
//        charFrequencyMap[s[i]][0]++;
//
//    }
//
//    strLenMap.push_back(charFrequencyMap);
//
//}

//bool isAnagramAvailable(vector<unordered_map<char, vector<int>>> &strLenMap, string &s,
//                        unordered_map<string, vector<string>> &result) {
//
//
//    for (int i = 0; i < strLenMap.size(); ++i) {
//        string currStr = "";
//        bool valid = true;
//
//        for (auto mapIterator = strLenMap[i].begin(); mapIterator != strLenMap[i].end(); ++mapIterator) {
//
//            mapIterator->second[1] = mapIterator->second[0];
//
//        }
//
//        for (int j = 0; j < s.length(); ++j) {
//
//            if (strLenMap[i].find(s[j]) == strLenMap[i].end()) {
//                valid = false;
//                break;
//            }
//
//            strLenMap[i][s[j]][1]--;
//
//        }
//
//        if (!valid) {
//            continue;
//        }
//
//        for (auto mapIterator = strLenMap[i].begin(); mapIterator != strLenMap[i].end(); ++mapIterator) {
//            currStr += mapIterator->first;
//            if (mapIterator->second[1] > 0) {
//                valid = false;
//            }
//
//        }
//
//        if (valid) {
//            result[currStr].push_back(s);
//            return true;
//        }
//
//    }
//
//    return false;
//
//}


//vector<vector<string>> groupAnagrams(vector<string> &strs) {
//
//    unordered_map<int, vector<unordered_map<char, vector<int>>>> lenToPossibleStringsMap;
//    unordered_map<string, vector<string>> result;
//    vector<vector<string>> resultx;
//
//    for (int i = 0; i < strs.size(); ++i) {
//
//        int currStrLen = strs[i].length();
//        bool isValidAnagramAvailable;
//
//        if (lenToPossibleStringsMap.find(currStrLen) == lenToPossibleStringsMap.end()) {
//            isValidAnagramAvailable = false;
//        } else {
//            // search in possible string maps and see if valid anagram available
//            isValidAnagramAvailable = isAnagramAvailable(lenToPossibleStringsMap[currStrLen], strs[i], result);
//        }
//
//
//        if (!isValidAnagramAvailable) {
//            addStrToVec(lenToPossibleStringsMap[currStrLen], strs[i]);
//            vector<string> v = {strs[i]};
//            result[strs[i]] = v;
//
//            // add curr string to frequency mapping
//        }
//
//    }
//
//    for (auto mapIterator = result.begin();
//         mapIterator != result.end(); ++mapIterator) {
//
//        resultx.push_back(mapIterator->second);
//
//    }
//
//    return resultx;
//
//
//}

string getHash(string& s){

    vector<int> freq(26,0);
    string res = "";

    for (int i = 0; i < s.length(); ++i) {
        freq[s[i]-'a']++;
    }

    for (int j = 0; j < freq.size(); ++j) {
        res = res + to_string(freq[j]) + "#";
    }

    return res;

}

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> anagramsHashMap;
    vector<vector<string>> result;

    for (int i = 0; i < strs.size(); ++i) {

        string hash = getHash(strs[i]);

        if(anagramsHashMap.find(hash) == anagramsHashMap.end()){
            vector<string> v = {strs[i]};
            anagramsHashMap.insert(make_pair(hash, v));
        }else{
            anagramsHashMap[hash].push_back(strs[i]);
        }

    }

    for (auto mapIterator = anagramsHashMap.begin(); mapIterator != anagramsHashMap.end(); ++mapIterator) {

        result.push_back(mapIterator->second);

    }

    return result;

}

int main() {

    vector<string> s = {""};
    vector<vector<string>> res = groupAnagrams(s);

    for (int i = 0; i < res.size(); ++i) {
        cout << "size : " << res[i].size() << " strs : ";
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ,";
        }

        cout << endl;
    }

    return 0;
}