//
// Created by Siddhant on 2019-11-05.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<vector<int>> result;

vector<vector<int>> permute(vector<int>& curr, vector<int>& nums) {

    if(nums.size() == 1){
        curr.push_back(nums[0]);
        result.push_back(curr);
        return result;
    }

    for (int i = 0; i < nums.size(); ++i) {

        int first = nums[i];
        vector<int> z = nums;
        vector<int> x = curr;

        z.erase(z.begin()+i);
        x.push_back(first);
        permute(x, z);
    }

    return result;

}

int main(){

    vector<int> nums = {1,2};
    vector<int> curr;
    permute(curr, nums);
    for (auto res = result.begin(); res != result.end(); ++res) {


        for (auto p = (*res).begin(); p != (*res).end(); ++p) {

            cout << (*p) << ',';

        }

        cout << endl;
    }
    return 0;
}