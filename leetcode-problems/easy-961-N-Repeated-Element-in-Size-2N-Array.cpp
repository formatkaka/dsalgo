//
// Created by Siddhant on 2019-09-11.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

int main(){

    vector<int> A = {5,1,5,2,5,3,5,4};
    int veclength = A.size();
    if(A[veclength/2] == A[(veclength/2) + 1]) return A[veclength/2];

    for (int i = 0; i < A.size(); ++i) {
        if(A[i] == A[A.size() - i - 1]){
            return A[i];
        }
    }

    return 0;
}



//
//    for (int i = 0; i < A.size(); ++i) {
//         auto existsInSet = hashmap.find(A[i]);
//
//         if(existsInSet == hashmap.end()){
//             hashmap.insert(A[i]);
//         }else{
//             return A[i];
//         }
//    }

/*
 * Attempt 1:
 *
 * Faster than only 54%.
 *
 * Possible optimisations :
 *  Incorrect - 1. Use 2 pointers, as at somepoint, atleast once, 2 elements will be the same. That will reduce iterations to half.
 *
 *
 */