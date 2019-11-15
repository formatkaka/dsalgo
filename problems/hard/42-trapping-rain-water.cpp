//
// Created by Siddhant on 2019-11-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

// PREVIOUS SOLUTION CALCULATING WATER PER HORIZONAL LEVEL
//int trap(vector<int> &height) {
//    int capacity = 0;
//    int maxheight = INT_MIN;
//
//    for (int j = 0; j < height.size(); ++j) {
//        maxheight = max(maxheight, height[j]);
//    }
//
//
//    while(maxheight >= 0){
//
//        bool searchStart = true, searchEnd = false;
//        int d = 0, start = 0, end = -1;
//        vector<int> levelArray(height.size(), 0);
//
//        for (int j = 0; j < height.size(); ++j) {
//
//            if(height[j] >= 1){
//                levelArray[j] = 1;
//                height[j]--;
//            }
//
//        }
//
//        for (int i = 0; i < levelArray.size(); ++i) {
//            if(levelArray[i] == 1){
//                start = i;
//                break;
//            }
//        }
//
//        while(start < levelArray.size()){
//
//            int end = start+1;
//            while(end < levelArray.size() && levelArray[end]!=1){
//                end++;
//            }
//
//            if(end < levelArray.size()){
//                capacity += (end - start - 1);
//            }
//
//            start = end;
//
//        }
//
//        for (int i = 0; i < height.size(); ++i) {
//
//            if(searchStart && height[i] >= 1 ){
//                searchEnd = true;
//                searchStart = false;
//                height[i]--;
//                start = i;
//                continue;
//            }
//
//            if(searchEnd && height[i] == 0){
//                d++;
//            }
//
//            if(searchEnd && height[i] >= 1){
//
//                if(d > 0){
//                    capacity += d;
//                    height[i]--;
//                    d = 0;
//                    searchEnd = false;
//                    searchStart = true;
//                }else{
//                    i--;
//                }
//
//
//            }
//
//        }
//
//        maxheight--;
//    }
//
//    return capacity;
//
//}

// CALCULATING WATER PER VERTICAL LEVEL
int trap(vector<int> &height) {
    int hlen = height.size(), capacity = 0;

    vector<int> leftmax(hlen, 0), rightmax(hlen, 0);

    leftmax[0] = height[0];
    for (int i = 1; i < hlen; i++) {
        leftmax.push_back(max(height[i], height[i - 1]));
    }


    rightmax[hlen - 1] = height[hlen - 1];
    for (int i = hlen - 2; i >= 0; i--) {
        rightmax[i] = max(height[i], height[i + 1]);
    }

    for (int i = 1; i < hlen - 1; i++) {
        capacity += min(leftmax[i], rightmax[i]) - height[i];
    }

    return capacity;

}

int main() {

    vector<int> v = {4, 2, 1, 0, 3, 5};
//    vector<int> v= {6,4,3,2,5,7};
    cout << "capcity is : " << trap(v) << endl;
    return 0;
}