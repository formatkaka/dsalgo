//
// Created by Siddhant on 2019-11-06.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k) {

    unordered_map<int, int> map;
    vector<vector<int>> soln;
    for (int i = 0; i < nums.size(); ++i) {

        map[nums[i]]++;

    }
    int minIndex = 0, currIndex = 0;
    for (auto mapIterator = map.begin(); mapIterator != map.end(); ++mapIterator) {

        int number = (*mapIterator).first;
        int frequency = (*mapIterator).second;
        vector<int> v = {frequency, number};

        if (soln.size() < k) {
            soln.push_back(v);

            if(frequency < soln[minIndex][0]){
                minIndex = currIndex;
            }

            currIndex++;
            continue;
        }


        if(frequency < soln[minIndex][0]){
            continue;
        }

        swap(soln[minIndex], v);

        for (int i = 0; i < soln.size(); ++i) {
            if(soln[i][0] < soln[minIndex][0]){
                minIndex = i;
            }
        }

    }

    vector<int> result;
    for (int j = 0; j < soln.size(); ++j) {
        result.push_back(soln[j][1]);
    }

    return result;

}

int main() {

    vector<int> nums = {1,1,2,3,4,4,5,5,6,6,6,7,7,7,7};
    vector<int> sol = topKFrequent(nums, 2);

    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << ',' ;
    }

    return 0;
}