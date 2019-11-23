//
// Created by Siddhant on 2019-11-04.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int maxSubArray(vector<int> &nums) {

    if (nums.size() == 1) {
        return nums[0];
    }

    int maxSum = nums[0];
    int sumTillNow = nums[0];

//    for (int i = 1; i < nums.size(); ++i) {
//
//        sumTillNow = max(sumTillNow+nums[i], nums[i]);
//        maxSum = max(maxSum, sumTillNow);
//
//    }

    for (int i = 1; i < nums.size(); ++i) {

        if (nums[i] > (sumTillNow + nums[i])) {
            maxSum = max(maxSum,nums[i]);
            sumTillNow = nums[i];
        } else {
            sumTillNow += nums[i];
            maxSum = max(sumTillNow, maxSum);
        }

    }

    return maxSum;

}

int main() {

    vector<int> vec = {-1,-2};

    cout << "max sum of subarray is : " << maxSubArray(vec);

    return 0;
}