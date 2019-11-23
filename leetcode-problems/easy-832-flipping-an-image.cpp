//
// Created by Siddhant on 2019-09-03.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void printVec(vector<int>& vec){
    for (auto wrapIter = vec.begin(); wrapIter != vec.end(); ++wrapIter) {
        std::cout << *wrapIter << " ";
    }
    cout << endl;
}

int invertDigit(int inputDigit){
    if(inputDigit == 0){
        return 1;
    }

    return 0;
}

vector<int> reverseAndInvert(vector<int>& vec){

    vector<int> output;
    printVec(vec);
    for (auto begin1 = vec.end() - 1; begin1 != vec.begin() - 1; --begin1) {
        output.push_back(invertDigit(*begin1));
    }
    printVec(output);
    cout << endl;
    return output;

}

int main(){

//    vector<vector<int>> A{{1,1,0},{1,0,1},{0,0,0}};
    vector<vector<int>> A{{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    int index = 0;

    for (auto wrapIter = A.begin(); wrapIter != A.end(); ++wrapIter, ++index) {
        A[index] = reverseAndInvert(*wrapIter);
    }

//    std::cout << A[0][0] << " " << A[0][1] << " " << A[0][2] << " " << A[0][3] << endl;
//    std::cout << A[1][0] << " " << A[1][1] << " " << A[1][2] << " " << A[1][3] << endl;
//    std::cout << A[2][0] << " " << A[2][1] << " " << A[2][2] << " " << A[2][3] << endl;
//    std::cout << A[3][0] << " " << A[3][1] << " " << A[3][2] << " " << A[3][3] << endl;


    return 0;
}

/*
 *  FINAL SOLUTION ON LEETCODE
 *
    class Solution {
    public:

        void reverseAndInvert(vector<int>& vec){

            std::reverse(vec.begin(), vec.end());
            for (int i = 0; i < vec.size(); i++) {
                vec[i] = vec[i]^1;
            }
        }

        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
            int index = 0;

            for (auto wrapIter = A.begin(); wrapIter != A.end(); ++wrapIter, ++index) {
                reverseAndInvert(*wrapIter);
            }

            return A;
        }
    };

    // Dont know why still 12ms
 *
 */