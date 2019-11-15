//
// Created by Siddhant on 2019-11-13.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int maxAreaAppr1(vector<int> &height) {

    int maxWater = INT_MIN;

    for (int i = 0; i < height.size(); ++i) {

        for (int j = i+1; j < height.size(); ++j) {

            maxWater = max(min(height[i], height[j])*(j-i), maxWater);

        }

    }

    return maxWater;

}

int maxArea(vector<int> &height) {

    int maxWater = INT_MIN;
    int startIndex = 0, endIndex = height.size()-1;
    int d = height.size()-1;

    while(startIndex < endIndex){

        if(height[startIndex] < height[endIndex]){
            maxWater = max(height[startIndex]*d, maxWater);
            startIndex++;
        }else{
            maxWater = max(height[endIndex]*d, maxWater);
            endIndex--;
        }

        d--;


    }

    return maxWater;

}

int main() {

    vector<int> wa = {1,8,6,2,5,4,8,3,7};
    cout << "max water contained is : " << maxArea(wa);
    return 0;
}