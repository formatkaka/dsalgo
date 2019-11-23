//
// Created by Siddhant on 2019-09-11.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    vector<int> A = {-7,-3,2,3,11};

    auto start = A.begin();
    auto end = A.end() - 1;
    vector<int> output;

    while(start <= end){

        int startnum = abs(*start);
        int endnum = abs(*end);

        if(startnum >= endnum){
            output.push_back(startnum*startnum);
            start++;
        }else{
            output.push_back(endnum*endnum);
            end--;
        }
    }

    reverse(output.begin(), output.end());
    for (int i = 0; i < output.size(); ++i) {
        cout << " i , val " << i << " " << output[i] << endl;
    }
    return 0;
}