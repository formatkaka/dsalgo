//
// Created by Siddhant on 2019-11-27.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void find(vector<int> inp, int index, vector<int> curr){

    if(index > inp.size() -1){
        for (int i = 0; i < curr.size(); ++i) {
            cout << curr[i] << " , ";
        }
        cout << endl;
        return;
    }

    vector<int> c = curr;
    curr.push_back(inp[index]);

    find(inp, index+1, curr);
    find(inp, index+1, c);

}

int LIS(vector<int> inp){
    vector<int> c = {};
    find(inp, 0, c);
}

int main(){

    vector<int> k = {3, 10, 2, 1, 20};
    LIS(k);
    return 0;
}