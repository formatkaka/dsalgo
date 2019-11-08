//
// Created by Siddhant on 2019-11-07.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int findCenter(vector<int> &nums) {

    if (nums[0] < nums[nums.size() - 1]) {
        return 0;
    }

    if (nums.size() == 1) {
        return 0;
    }

    int start = 0;
    int end = nums.size() - 1;
    int mid;

    while (start < end) {
        mid = (start + end) / 2;


        if (nums[mid] < nums[start] && nums[mid - 1] > nums[mid]) {
            return mid;
        }

        if (nums[mid] > nums[start]) {
            start = mid;
        } else {
            end = mid;
        }


    }

    return mid + 1;

}

int binSearch(vector<int> &nums, int target, int startIndex, int endIndex) {

    int mid;

    while (startIndex <= endIndex) {

        mid = (startIndex + endIndex) / 2;

        if (nums[mid] == target) {
            return mid;
        }


        if (nums[mid] > target) {
            endIndex = mid - 1;
        } else {
            startIndex = mid + 1;
        }

    }

    return -1;

}

int search(vector<int> &nums, int target) {

    int getCenter = findCenter(nums);
    if (target <= nums[nums.size() - 1]) {
        return binSearch(nums, target, getCenter, nums.size() - 1);
    } else {
        return binSearch(nums, target, 0, getCenter - 1);
    }

}

int main() {

    vector<int> nums = {3, 1};
//    vector<int> nums = {4,5,6,7,0,1,2};
    cout << "center index : " << search(nums, 0);
    return 0;
}