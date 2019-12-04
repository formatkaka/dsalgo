//
// Created by Siddhant on 2019-12-04.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void printvec(vector<int> &v) {
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << ", ";
    }
    cout << endl;
}

int find(vector<int> &nums) {

    if (nums.size() == 3) {
        return nums[1];
    }

    int maxval = INT_MIN;

    for (int i = 1; i < nums.size() - 1; i++) {
        int x = nums[i];
        int mult = nums[i - 1] * nums[i] * nums[i + 1];
        nums.erase(nums.begin() + i);


        int val = mult + find(nums);
        nums.insert(nums.begin() + i, x);

        maxval = max(maxval, val);
    }

    return maxval;

}

int maxCoins(vector<int> &nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    return find(nums);
    // use list data structure for optimised delete
}

int main() {

    vector<int> a = {3,1,5,8};
//    a.insert(a.begin(), 0);
//    a.push_back(1);
    cout << maxCoins(a) << endl;
//    a.erase(a.begin() + 2);
//    printvec(a);
//    a.insert(a.begin() + 2, 3);
    printvec(a);
    return 0;
}