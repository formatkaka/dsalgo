//
// Created by Siddhant on 2019-11-06.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<int> productExceptSelf(vector<int> &nums) {
    int res = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        res ^= nums[i];
        cout << res << endl;
    }

}

int main() {

    vector<int> nums = {1,2,3,4};
    vector<int> result = productExceptSelf(nums);
    return 0;
}