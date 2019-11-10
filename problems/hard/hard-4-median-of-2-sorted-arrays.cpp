//
// Created by Siddhant on 2019-11-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len = nums1.size() + nums2.size();
    bool hasTwoMedians = false;
    int medians[2] = {(len + 1) / 2 - 1, -1};
    int searchingForMedian = 0;

    if (len % 2 == 0) {
        hasTwoMedians = true;
        medians[1] = (medians[0] + 1);
    }

    int p1 = 0, p2 = 0;
    double result = 0;
    double curr = 0;
    int currIndex;
    while (searchingForMedian < 2 && medians[searchingForMedian] >= 0) {



        currIndex = p1+p2;


        if (p2 < nums2.size() && p1 < nums1.size()) {
            if (nums1[p1] > nums2[p2]) {
                curr = nums2[p2];
                p2++;
            } else {
                curr = nums1[p1];
                p1++;
            }
        } else {

            if (p2 < nums2.size()) {
                curr = nums2[p2];
                p2++;
            } else {
                curr = nums1[p1];
                p1++;
            }

        }

        if (currIndex == medians[searchingForMedian]) {
            result += curr;
            searchingForMedian++;
        }

    }

    if (hasTwoMedians) {
        result /= 2;
    }

    return result;
}

int main() {
    vector<int> nums1 = {1,2,3};
//    for (auto begin2 = nums1.begin(); begin2 != nums1.end(); ++begin2) {
//        begin2->
//    }
    vector<int> nums2 = {};
    cout << "result : " << findMedianSortedArrays(nums1, nums2);
    return 0;
}