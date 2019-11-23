//
// Created by Siddhant on 2019-09-11.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool is_valid_number(int n){
    int orig = n;

    while(n > 0){

        int m = n%10;

        if(m==0) return false;
        if(orig%m != 0) return false;

        n = n/10;

    }
    return true;
}

int main(){

    int left = 1;
    int right = 22;
    vector<int> output;

    for (int i = left; i <= right; ++i) {
        if(is_valid_number(i)) output.push_back(i);
    }

//    for (int j = 0; j < output.size(); ++j) {
//        cout << output[j] << " " ;
//    }

    return 0;
}