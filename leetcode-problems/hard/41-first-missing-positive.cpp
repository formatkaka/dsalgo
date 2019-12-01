//
// Created by Siddhant on 2019-11-28.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int firstMissingPositive(vector<int> &nums) {



    for (int i = 0; i < nums.size(); ++i) {

        if(nums[i] <= 0 || nums[i] > nums.size()){
            nums[i] = -1;
        }

    }

    for (int j = 0; j < nums.size(); ++j) {
        while(nums[j] != -1 && nums[j] != j+1){

            if(nums[nums[j] - 1] == nums[j]){
                nums[j] = -1;
                break;
            }

            int temp = nums[j];
            nums[j] = nums[nums[j]-1];
            nums[temp-1] = temp;
        }

    }

    for (int k = 0; k < nums.size(); ++k) {

        if(nums[k] == -1){
            return k+1;
        }

    }

    return nums.size()+1;
}

int main() {

    vector<int> nums = {7,8,9,11,12};
    cout << firstMissingPositive(nums);
    return 0;
}