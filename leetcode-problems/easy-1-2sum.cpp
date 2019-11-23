//
// Created by Siddhant on 2019-11-08.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {

    unordered_map<int, vector<int>> map;
    vector<int> soln;
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]].push_back(i);
    }

    for (int j = 0; j < nums.size(); ++j) {

        int search = target - nums[j];



        if(map.find(search) != map.end()) {


            if (search == nums[j]) {

                if (map[search][map[search].size() - 1] > j) {
                    soln.push_back(map[search][map[search].size() - 1]);
                    soln.push_back(j);
                }
            } else {

                soln.push_back(map[search][0]);
                soln.push_back(j);
                break;
            }
        }

    }
    return soln;

}

int main() {

    vector<int> nums = {3, 3};
    vector<int> result = twoSum(nums, 6);
    cout << result[0] << "  " << result[1];
    return 0;
}