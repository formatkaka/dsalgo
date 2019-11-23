//
// Created by Siddhant on 2019-11-01.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"

using namespace std;

//int robDF(vector<int>& nums, int startIndex, int endIndex){
//
//    if(startIndex == endIndex){
//        return 0;
//    }
//
//    if(endIndex - startIndex < 3){
//        return *max_element(nums.begin()+startIndex, nums.begin()+endIndex);
//    }
//
//
//
//}

//int rob(vector<int>& nums) {
//
//    if(nums.empty()){
//        return 0;
//    }
//
//    if(nums.size() < 3){
//        return *max_element(nums.begin(), nums.end());
//    }
//
//    vector<int> subArr(nums.begin()+2, nums.end());
//    int opt1 = nums[0] + rob(subArr);
//    int opt2;
//
//    if(nums.size() == 3){
//        vector<int> subArr2 = {};
//        opt2 = nums[1] + rob(subArr2);
//    }else{
//        vector<int> subArr2(nums.begin()+3, nums.end());
//        opt2 = nums[1] + rob(subArr2);
//    }
//
//    return max(opt1, opt2);
//
//}

int robDF(vector<int>& nums, int index){
    unordered_map<int, int> map;

    if(index < 0){
        return 0;
    }

    if(map.find(index) != map.end()){
        cout << "index : " << index << " , val : " << map[index] << endl;
        return map[index];
    }

    int sum =  max(nums[index] + robDF(nums, index-2), robDF(nums, index-1) );
    map.insert(make_pair(index, sum));
    return sum;
}

int robIterative(vector<int>& nums){

    if(nums.empty()){
        return 0;
    }

    vector<int> memo;

    memo.push_back(nums[0]);
    memo.push_back(nums[1]);

    for (int i = 2; i < nums.size()   ; ++i) {

        int maxVal = max(memo[i-2] + nums[i], memo[i-1]);
        memo.push_back(maxVal);
    }

    return memo[memo.size()-1];

}

int rob(vector<int>& nums){
    return robDF(nums, nums.size()-1);
}

int main(){


//    cout << " at 12 : " << map[make_pair(1,2)] << endl;

    vector<int> nums = {183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    cout << "max theft possible is : " << robIterative(nums);
    return 0;
}