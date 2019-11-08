//
// Created by Siddhant on 2019-09-26.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<vector<int>> result;

void subsetsRec(vector<int>& tillNow,vector<int>& nums, int startIndex, int size){

    if(startIndex+size > nums.size()){
        return;
    }

    if(size == 0){
        result.push_back(tillNow);
        return;
    }

    size--;

    for (int i = startIndex; i < nums.size(); ++i) {

        vector<int> v = tillNow;
        v.push_back(nums[i]);
        subsetsRec(v, nums, i+1, size);

    }

}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<int> z;
    for (int i = 1; i <= nums.size() ; ++i) {
        subsetsRec(z, nums, 0, i);
        cout << i << " : " << result.size() << endl;
    }
    return result;

}

int main(){

    vector<int> nums = {1, 2, 3, 4};
    vector<vector<int>> result = subsets(nums);
    result.push_back({});
    for (auto res = result.begin(); res != result.end(); ++res) {
        cout << "el : ";
        for (auto r = (*res).begin(); r != (*res).end(); ++r) {

            cout << *r << ',';

        }

        cout << endl;

    }

    return 0;
}