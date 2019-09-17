//
// Created by Siddhant on 2019-09-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int binarySearchIterative(vector<int>* arr, int key){

    int low = 0;
    int high = arr->size() - 1;

    while(low <= high){
        if(low == high && (*arr)[low] == key){
            return low;
        }

        int mid = (low + high)/2;
        int el = (*arr)[mid];

        if(el == key) {
            return mid;
        }

        if(key < el){
            high = mid - 1;
        }else{
            low = mid + 1;
        }

    }

    return -1;

}

int binarySearchRecursive(vector<int>* arr,int low, int high, int key){

    if(low == high && (*arr)[low] == key){
        return low;
    }

    int mid = (low + high)/2;
    int el = (*arr)[mid];

    if(el == key) {
        return mid;
    }

    if(key < el){
        high = mid - 1;
    }else{
        low = mid + 1;
    }

    return binarySearchRecursive(arr, low, high, key);
}

int main(){

    vector<int> arr = {1,3,4,6,11,13,15,19,23,34,55,78,89};
    cout << "Key is at : " << binarySearchIterative(&arr, 55) << endl;
    cout << "Key is at : " << binarySearchRecursive(&arr,0,12, 55) << endl;

    return 0;
}