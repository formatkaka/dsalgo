//
// Created by Siddhant on 2019-09-16.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    vector<int> A = {0,2,1,0};
//    bool strictlyInc = true;
//    int sol = -1;
    for (int i = 1; i < A.size()-1; ++i) {
        int current = A[i];
        int prev = A[i-1];
        int next = A[i+1];

        if(current > prev && current > next){
            return i;
        }

//        if(strictlyInc && current > prev){
//            continue;
//        }
//
//        if(strictlyInc && current < prev){
//            // found the inflection point
//            sol = i-1;
//            strictlyInc = false;
//            continue;
//        }
//
////        if(!strictlyInc && current > prev){
////            return 0;
////        }



    }

    return 0;
}