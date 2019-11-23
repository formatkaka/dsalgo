//
// Created by Siddhant on 2019-09-03.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    vector<int> A{3,1,2,4};
    vector<int> output;

    for (int i = 0; i < A.size(); ++i) {
        if(A[i]%2 == 0) output.push_back(A[i]);
    }

    for (int i = 0; i < A.size(); ++i) {
        if(A[i]%2 != 0) output.push_back(A[i]);
    }


    return 0;
}