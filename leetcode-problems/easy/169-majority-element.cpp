//
// Created by Siddhant on 2019-12-01.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int majorityElement(vector<int> &nums) {

    int n = 7;
    int ones = 0;
    int result = 0;

    for (int i = 0; i < 32; ++i) {

        ones = 0;

        for (int j = 0; j < nums.size(); ++j) {

            if (nums[j] & 1 << i) {
                ones++;
            }

        }

        if(ones > nums.size()/2){
            result = result | (1 << i);
        }

    }

    return result;


}

int main() {

//    cout << (1<<4);
    vector<int> v = {2,2,1,1,1,2,2};
    cout << "result is : " << majorityElement(v);
    return 0;
}