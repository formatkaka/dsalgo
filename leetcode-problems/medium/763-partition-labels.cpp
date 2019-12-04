//
// Created by Siddhant on 2019-12-02.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

//        for (auto mapIt = m.begin(); mapIt != m.end(); ++mapIt) {
//
//            int dist = (mapIt->second[1] - mapIt->second[0] + 1);
//
//            if(dist > maxdist){
//                c = mapIt->first;
//                v = mapIt->second;
//                maxdist = dist;
//            }
//
//        }

using namespace std;

vector<int> partitionLabels(string S) {

    unordered_map<char, vector<int>> m;
    vector<int> result;



    for (int i = 0; i < S.length(); ++i) {

        char c = S[i];

        if(m.find(c) == m.end()){
            // if char not in map, add and keep start, end index same
            m[c].push_back(i);
            m[c].push_back(i);
            continue;
        }

        // update end index value
        m[c][1] = i;

    }

    int i = 0;

    while(!m.empty() && i < S.length()){

        // get top value in map
        char c = S[i];
        vector<int> v = m[c];
        vector<char> toerase;



        int minrange = v[0];
        int maxrange = v[1];

        int start = minrange + 1, end = maxrange;

        toerase.push_back(c);

        while(start < end){

            char ct =  S[start];
            vector<int> p = m[ct];
            if(minrange <= p[1] && p[0] <= maxrange ){
                minrange = min(minrange, p[0]);
                maxrange = max(maxrange, p[1]);
                end = maxrange;
                toerase.push_back(ct);
            }

            start++;

        }

        for (int i = 0; i < toerase.size(); ++i) {
            m.erase(toerase[i]);
        }

        i = maxrange+1;

        result.push_back(maxrange - minrange + 1);

    }

    return result;


}

int main() {

    string S = "qiejxqfnqceocmy";
    partitionLabels(S);
    return 0;
}