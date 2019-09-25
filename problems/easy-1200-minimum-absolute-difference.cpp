//
// Created by Siddhant on 2019-09-24.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
//void minimumAbsDifference(vector<int>& arr) {

    sort(arr.begin(), arr.end());

    // Finding Minimum absolute difference
    int minAbsDiff = INT_MAX;
    for (int i = 0; i < arr.size() - 1; ++i) {

        if(arr[i+1] - arr[i] < minAbsDiff){
            minAbsDiff = arr[i+1] - arr[i];
        }
    }

    vector<vector<int>> result;
    // Find subarrays
    for (int j = 0; j < arr.size() - 1; ++j) {
        int a = arr[j];
        int b = minAbsDiff + a;

        if(binary_search(arr.begin(), arr.end(), b)){
            vector<int> pair = {a, b};
            result.push_back(pair);
        }
    }

    return result;

}

int main(){

    vector<int> arr = {3,8,-10,23,19,-4,-14,27};
//    vector<int> arr = {1,3,6,10,15};
//    vector<int> arr = {4,2,1,3};
    vector<vector<int>> output = minimumAbsDifference(arr);

    for (auto pairs = output.begin(); pairs != output.end(); ++pairs) {
        cout << "el : " ;
        for (auto el = (*pairs).begin(); el != (*pairs).end(); ++el) {
            cout << (*el) << " " ;
        }
        cout << endl;
    }

    return 0;
}

/*
 *    Optimization :
 *
 *    if(binary_search(arr.begin(), arr.end(), b)){
 *       vector<int> pair = {a, b};
 *       result.push_back(pair);
 *     }
 *
 *     replace by
 *     if(arr[j+1] == b){
 *       ...
 *     }
 *
 *     Since we are dealing with min absolute difference, any two valid elements
 *     will always be adjacent.
 */