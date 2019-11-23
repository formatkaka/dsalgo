//
// Created by Siddhant on 2019-11-20.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {


        int ptr_m = m - 1;
        int ptr_n = n - 1;
        int i = m+n-1;

        while(ptr_n >= 0 && ptr_m >= 0){

            if(nums1[ptr_m] > nums2[ptr_n]){
                int temp = nums1[ptr_m];
                nums1[ptr_m] = nums1[i];
                nums1[i] = temp;
                ptr_m--;
            }else{
                nums1[i] = nums2[ptr_n];
                ptr_n--;
            }

            i--;

        }

        while(ptr_n >= 0){

            nums1[i] = nums2[ptr_n];
            ptr_n--;
            i--;

        }

//    for (int j = 0; j < nums1.size(); ++j) {
//
//        cout << nums1[j] << ", " ;
//
//    }
}

int main() {

    vector<int> v1 = {4,5,6,0,0,0};
    vector<int> v2 = {1,2,3};
    merge(v1, 3, v2, 3);
    char k = 'a'+1;
    cout << k;

    return 0;
}