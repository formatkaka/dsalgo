//
// Created by Siddhant on 2019-11-01.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

int singleNumber(vector<int>& nums) {

    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); ++i) {

        if(map.find(nums[i]) != map.end()){
            map[nums[i]]++;
        }else{
            map[nums[i]] = 1;
        }

    }

    for (auto mapIterator = map.begin(); mapIterator != map.end(); ++mapIterator) {
            if(mapIterator->second == 1){
                return mapIterator->first;
            }
    }

}

int main(){

    vector<int> vec = {0,1,0,1,0,1,99};
    cout << "ans : " << singleNumber(vec);

    return 0;
}