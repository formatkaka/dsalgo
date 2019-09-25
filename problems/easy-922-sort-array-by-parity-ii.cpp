//
// Created by Siddhant on 2019-09-20.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<int> sortArrayByParityII(vector<int>& A) {

    vector<int> evenIndexInvalid;
    vector<int> oddIndexInvalid;

    for (int i = 0; i < A.size(); ++i) {

        int a = A[i];
        bool indexIsEven = i%2 == 0;
        bool validEl = (i%2 ==0 && A[i]%2 == 0) || (i%2 != 0 && A[i]%2 != 0);

        if(validEl) continue;

        // invalid element
        if(indexIsEven){
            evenIndexInvalid.push_back(i);
        }else{
            oddIndexInvalid.push_back(i);
        }

    }

    for (int j = 0; j < evenIndexInvalid.size(); ++j) {
        int evenIndex = evenIndexInvalid[j];
        int oddIndex = oddIndexInvalid[j];

        int temp = A[evenIndex];
        A[evenIndex] = A[oddIndex];
        A[oddIndex] = temp;
    }

    return A;

}

int main(){

    vector<int> A {4,2,5,7};
    vector<int> output = sortArrayByParityII(A);

    for (auto out = output.begin(); out != output.end(); ++out) {
        cout << "out " << (*out) << endl;
    }

    return 0;
}

/*
 *
 *  Good alternate solution - https://leetcode.com/problems/sort-array-by-parity-ii/discuss/181158/C%2B%2B-5-lines-two-pointers-%2B-2-liner-bonus
 *
 *   vector<int> sortArrayByParityII(vector<int>& A) {
 *       for (int i = 0, j = 1; i < A.size(); i += 2, j += 2) {
 *           while (i < A.size() && A[i] % 2 == 0) i += 2;
 *           while (j < A.size() && A[j] % 2 == 1) j += 2;
 *           if (i < A.size()) swap(A[i], A[j]);
 *       }
 *       return A;
 *   }
 */