//
// Created by Siddhant on 2019-11-12.
//

/*
 * class Solution {
public:
    string minWindow(string s, string t) {

        if(t.length() > s.length()){
            return "";
        }

        unordered_map<char, int> tmap;
        unordered_map<char, vector<int>> smap;

        for (int i = 0; i < t.length(); ++i) {
            tmap[t[i]]++;
        }

        for (int j = 0; j < s.length(); ++j) {

            if (tmap.find(s[j]) != tmap.end()) {
                smap[s[j]].push_back(j);
            }

        }

        vector<int> v;
        int globalMin = -1, globalMax, minLen = INT_MAX;
        bool exitLoop = false;
        while (!exitLoop) {
            int minIndex = INT_MAX, maxIndex = INT_MIN;
            char c;
            for (auto tm = tmap.begin(); tm != tmap.end(); ++tm) {

                int occurences = 0;

                while (occurences < tm->second) {

                    if (smap[tm->first].empty()  ||   occurences == smap[tm->first].size() ) {
                        exitLoop = true;

                        break;
                    }

                    if (smap[tm->first][occurences] < minIndex) {
                        minIndex = smap[tm->first][occurences];
                        c = tm->first;
                    }

                    if (smap[tm->first][occurences] > maxIndex) {
                        maxIndex = smap[tm->first][occurences];
                    }

                    // break condition if not in vector
                    occurences++;
                }

                if (exitLoop) {
                    break;
                }

            }

            if (!exitLoop) {


                smap[c].erase(smap[c].begin());

                if (maxIndex - minIndex < minLen) {
                    globalMin = minIndex;
                    globalMax = maxIndex;
                    minLen = maxIndex - minIndex;
                }
            }

        }

        if(globalMin == -1){
            return "";
        }

        return s.substr(globalMin, minLen + 1);

    }
};
 *
 */

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

string minWindow(string s, string t) {

    unordered_map<char, int> tmap;
    unordered_map<char, vector<int>> smap;

    for (int i = 0; i < t.length(); ++i) {
        tmap[t[i]]++;
    }

    for (int j = 0; j < s.length(); ++j) {

        if (tmap.find(s[j]) != tmap.end()) {
            smap[s[j]].push_back(j);
        }

    }

    vector<int> v;
    int globalMin = -1, globalMax, minLen = INT_MAX;
    bool exitLoop = false;
    while (!exitLoop) {
        int minIndex = INT_MAX, maxIndex = INT_MIN;
        char c;
        for (auto tm = tmap.begin(); tm != tmap.end(); ++tm) {

            int occurences = 0;

            while (occurences < tm->second) {

                if (smap[tm->first].empty() ||   occurences == smap[tm->first].size() ) {
                    exitLoop = true;

                    break;
                }

                if (smap[tm->first][occurences] < minIndex) {
                    minIndex = smap[tm->first][occurences];
                    c = tm->first;
                }

                if (smap[tm->first][occurences] > maxIndex) {
                    maxIndex = smap[tm->first][occurences];
                }

                // break condition if not in vector
                occurences++;
            }

            if (exitLoop) {
                break;
            }

        }

        if (!exitLoop) {


            smap[c].erase(smap[c].begin());

            if (maxIndex - minIndex < minLen) {
                globalMin = minIndex;
                globalMax = maxIndex;
                minLen = maxIndex - minIndex;
            }
        }

    }

    if(globalMin == -1){
        return "";
    }
    return s.substr(globalMin, minLen + 1);

}

int main() {

    string S = "ADOBECODEBANC";
    string T = "ABC";

    cout << "ans : " << minWindow(S, T);

    return 0;
}