//
// Created by Siddhant on 2019-09-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;


void merge(vector<int>*arr,int low, int mid, int high){

    int i = low;
    int j = mid+1;
    int index = 0;
    int output[high - low + 1];

    while (i <= mid && j <= high){

        int num1 = (*arr)[i];
        int num2 = (*arr)[j];

        if(num1 <= num2){
            output[index++] = num1; // low is position in output array
            i++; // i,j are two-pointers in input array
        }else{
            output[index++] = num2;
            j++;
        }

    }

    for (int k = i; k <= mid; k++) {
        output[index++] = (*arr)[k];
    }

    for (int l = j; l <= high; l++) {
        output[index++] = (*arr)[l];
    }

    for (int m = low; m <= high; m++) {
        (*arr)[m] = output[m - low];
    }

}

void merge_sort(vector<int>*arr, int low, int high){

    if(low < high){
        int mid = (low+high)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }else{
        return;
    }

}

int main(){

    vector<int> arr = {12,3,41,16,121,3,5,19,23,8,55,18,89};
    merge_sort(&arr, 0, 12);
    for (int i = 0; i < 13; ++i) {
        cout << " i " << arr[i] << endl;
    }
    return 0;
}