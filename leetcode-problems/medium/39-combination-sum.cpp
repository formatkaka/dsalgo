//
// Created by Siddhant on 2019-11-16.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;

string getHash(vector<int> &vec) {
    string s = "";
    for (int i = 0; i < vec.size(); i++) {
        s = s + to_string(vec[i]) + "#";
    }

    return s;
}

void mergeVectors(unordered_map<int, vector<vector<int>>> &map,unordered_map<int, int>& canset, int i, int target) {

    unordered_set <string> maintainUnique;
    vector<vector<int>> result;

    for (int j = 1; j <= i / 2; j++) {

        if (!map[j].empty() && !map[i - j].empty()) {

            for (int k = 0; k < map[j].size(); k++) {
                vector<int> v;
                for (int l = 0; l < map[i - j].size(); l++) {

                    v = map[j][k];
                    for (int m = 0; m < v.size(); m++) {
                        v[m] += map[i - j][l][m];
                    }

                }

                string hash = getHash(v);

                if (maintainUnique.find(hash) == maintainUnique.end()) {
                    maintainUnique.insert(hash);
                    result.push_back(v);
                }

            }
        }
    }

    if(i == target && !map[1].empty()){
        vector<int> ones(canset.size(), 0);
        ones[canset[1]] = target;
        string hash = getHash(ones);
        if (maintainUnique.find(hash) == maintainUnique.end()) {
            maintainUnique.insert(hash);
            result.push_back(ones);
        }
    }


    map[i] = result;
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target) {


    unordered_map<int, vector<vector<int>>> map;

    unordered_map<int, int> canset;

    for (int i = 0; i < candidates.size(); i++) {
        canset.insert(make_pair(candidates[i], i));
    }

    for (int i = 1; i <= target; i++) {

        unordered_set <string> hash;
        vector<vector<int>> t;

        map[i] = t;


        mergeVectors(map, canset,i, target);

        if (canset.find(i) != canset.end()) {
            vector<int> sol(candidates.size(), 0);
            sol[canset[i]] = 1;
            map[i].push_back(sol);
        }

    }

    vector<vector<int>> result;

    for (int i = 0; i < map[target].size(); i++) {
//        cout << "map target size  : " << map[target].size() << endl;
        vector<int> v;
        result.push_back(v);
        for (int j = 0; j < map[target][i].size(); j++) {

            for (int k = 0; k < map[target][i][j]; k++) {
                result[i].push_back(candidates[j]);
            }

        }

    }



    return result;

}

int main() {

    vector<int> can = {3,4,7,8};
    int target = 11;
    vector<vector<int>> res =combinationSum(can, target);

    for (auto row = res.begin(); row != res.end(); ++row) {

        for (auto el = (*row).begin(); el != (*row).end(); ++el) {
            cout << *el << ' ';
        }
        cout << endl;

    }

    return 0;
}