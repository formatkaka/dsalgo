//
// Created by Siddhant on 2019-11-08.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void printVariations(vector<int> &nums, vector<int> &curr, int k, int startIndex, int sumTillNow, int target) {

    if (curr.size() == k) {

        if (sumTillNow == target) {

            for (int i = 0; i < curr.size(); ++i) {
                cout << curr[i] << ',';
            }
            cout << endl;
        }
        return;
    }

    if (nums.size() - startIndex + curr.size() < k) {
        return;
    }

    int num = nums[startIndex];
    curr.push_back(num);
    startIndex++;

    printVariations(nums, curr, k, startIndex, sumTillNow + num, target);
    curr.pop_back();
    printVariations(nums, curr, k, startIndex, sumTillNow, target);

}



vector<vector<int>> fourSum(vector<int> &nums, int target) {


}

int main() {

    vector<int> nums = {1, 2, 2, 4, 5, 6, 7};
    vector<int> curr;
    printVariations(nums, curr, 4, 0, 0, 12);
    return 0;
}