//
// Created by Siddhant on 2019-10-14.
//

#include "iostream"
#include "vector"
#include "string"
#include "math.h"

using namespace std;

vector<int> countBits(int num) {

    if(num == 0){
        return {0};
    }

    if(num == 1){
        return {0, 1};
    }

    vector<int> res = {0,1};

    int n = 2;

    while(n <= num){

        int k = (int) log2(n);
        int st = (int) pow(2, k);
        res.push_back(1 + res[n - st]);
        n++;
    }

    return res;
}

int main(){

    int num = 5;
    vector<int> soln = countBits(num);
    int i = 0;
    for (auto bitCount = soln.begin(); bitCount != soln.end(); ++bitCount, ++i) {
        cout << "bit count in " << i << " is : " << (*bitCount) << endl;
    }

    return 0;
}