//
// Created by Siddhant on 2019-11-29.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

int findMinIndex(int curr_max, vector<int> & indexes){

    for (int i = 0; i < indexes.size(); ++i) {

        if(indexes[i] > curr_max){
            return indexes[i];
        }

    }

    // not found desired index
    return -1;

}

int shortestWay(string source, string target) {

    if(target.empty() && source.empty()){
        return -1;
    }

    if(target.empty() || source.empty()){
        return -1;
    }

    unordered_map<char, vector<int>> m;

    for (int i = 0; i < source.length(); ++i) {

        char c = source[i];
        m[c].push_back(i);

    }

    int substrings_count = 0;

    int curr_max = -1;

    for (int j = 0; j < target.length(); ++j) {

        char t = target[j];

        if(m.find(t) == m.end()){
            // if char not found in source, exit
            return -1;
        }

        curr_max = findMinIndex(curr_max, m[t]);

        if(curr_max == -1){
            // the current alphabet was not found for desired range.
            // Increment the substrings_count here because we now need to begin again.

            substrings_count++;

            // re-find curr max , for the current char with new value
            curr_max = findMinIndex(curr_max, m[t]);

        }

    }

    return substrings_count+1;

}

int main() {

    string src = "xzyxzccc";
    string target = "";
    cout << "ans is : " << shortestWay(src, target);
    return 0;
}