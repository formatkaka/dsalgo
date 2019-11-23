//
// Created by Siddhant on 2019-11-08.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "algorithm"

using namespace std;

string hashVec3(int n1, int n2, int n3){
    return to_string(n1) + "." + to_string(n2) + "." + to_string(n3);
}

vector<vector<int>> threeSum(vector<int> &nums) {

    unordered_map<int, vector<int>> map;
    unordered_set<string> seen;
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]].push_back(i);
    }

    for (int i = 0; i < nums.size(); ++i) {

        for (int j = i+1; j < nums.size() ; ++j) {

            int sumIJ = nums[i] + nums[j];
            int K = -1*sumIJ;
            cout << " j : " << j << endl;
            if(map.find(K) != map.end() && map[K][map[K].size()-1] > j){

                string hash = hashVec3(nums[i], nums[j], K);
                if(seen.find(hash) == seen.end()){
                    result.push_back({nums[i], nums[j], K});
                    seen.insert(hash);
                }

                while(j < nums.size()-1 && nums[j] == nums[j+1]){
                    j++;
                }

                cout << " j while : " << j << endl;

            }



        }

    }

    for (auto resVec = result.begin(); resVec != result.end(); ++resVec) {

        for (auto r = (*resVec).begin(); r != (*resVec).end(); ++r) {

            cout << (*r) << ',';

        }

        cout << endl;

    }
    return result;
}

int main() {

    vector<int> nums = {0,0,0,0,0,0,0};
    threeSum(nums);
    return 0;
}