//
// Created by Siddhant on 2019-11-01.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int missingNumber(vector<int>& nums) {

    int arrSize = nums.size();
    int idealSum = arrSize*(arrSize+1)/2;

    int numsSum = 0;

    for (int i = 0; i < arrSize; ++i) {
        numsSum += nums[i];
    }

    return  idealSum - numsSum;

}

int main(){

    vector<int> vec = {9,6,4,2,3,5,7,0,1};
    cout << "missing number is : " << missingNumber(vec);
    return 0;
}