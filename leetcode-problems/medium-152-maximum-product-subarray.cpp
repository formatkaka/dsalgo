//
// Created by Siddhant on 2019-11-02.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;


//int maxProduct(vector<int>& nums, int startIndex, int endIndex) {
//
//    if(endIndex - startIndex < 2){
//        return nums[endIndex];
//    }
//
//    static int maxVal = INT_MIN;
//
//    for (int divider1= startIndex; divider1 <= endIndex - 2; ++divider1) {
//
//        for (int divider2 = divider1+1; divider2 <= endIndex-1; ++divider2) {
//
//            int maxEl1 = maxProduct(nums, startIndex, divider1);
//            int maxEl2 = maxProduct(nums, divider1, divider2);
//            int maxEl3 = maxProduct(nums, divider2, endIndex);
//
//            int overlapEl1El2 = maxEl1*maxEl2;
//            int overlapEl2El3 = maxEl2*maxEl3;
//            int overlapEl1El2El3 = maxEl1*maxEl2*maxEl3;
//
//            maxVal = max({maxVal, maxEl1, maxEl2, maxEl3, overlapEl1El2, overlapEl2El3, overlapEl1El2El3});
//
//        }
//    }
//
//    return maxVal;
//
//}

int maxProduct(vector<int>& nums){

    int maxSum = nums[0];
    int minSum = nums[0];

    int m1 = INT_MIN;

    for (int i = 1; i < nums.size(); ++i) {

        int newMaxSum = max({nums[i], maxSum*nums[i], minSum*nums[i]});
        int newMinSum = min({nums[i], minSum*nums[i], maxSum*nums[i]});

        maxSum = newMaxSum;
        minSum = newMinSum;

        m1 = max(m1, maxSum);

    }

    return m1;

}

int main(){

    vector<int> vec = {-1,1,-1,2,0,-6};
    cout << "max product : " << maxProduct(vec);
    return 0;
}