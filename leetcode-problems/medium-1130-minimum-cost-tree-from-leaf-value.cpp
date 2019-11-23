//
// Created by Siddhant on 2019-10-31.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "unordered_map"

using namespace std;

unordered_map<string, int> map;

string vecToString(vector<int> vec){
    string res = "";
    for (int i = 0; i < vec.size(); ++i) {
        res += vec[i] + ',';
    }
    return res;
}

int mctFromLeafValues(vector<int>& arr) {


    if(arr.size() == 1){
        return 0;
    }

    string st = vecToString(arr);
    if(!map.empty() && (map.find(st) != map.end())){
        cout << "using from cache : " << st << " " << map[st] << endl;
        return map[st];
    }

    int maxSum = INT_MAX;
    for (int i = 1; i < arr.size(); ++i) {

        vector<int> arrLeft(arr.begin(), arr.begin()+i);
        vector<int> arrRight(arr.begin()+i, arr.end());
        int leftSum = mctFromLeafValues(arrLeft);
        int rightSum = mctFromLeafValues(arrRight);



        int rootMult = (*max_element(arrLeft.begin(), arrLeft.end()))*(*max_element(arrRight.begin(), arrRight.end()));

        int sum = leftSum + rightSum + rootMult;
        maxSum = min(maxSum, sum);
    }

    map.insert(make_pair(st, maxSum));

    return maxSum;
}

int main(){

    vector<int> vec = {1,2,3,4,5,6,7,8};

    cout << "ans : " << mctFromLeafValues(vec);
    return 0;
}