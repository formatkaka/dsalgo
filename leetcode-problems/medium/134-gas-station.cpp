//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {

    int total_sum = 0;

    for (int i = 0; i < gas.size(); ++i) {

        total_sum += (gas[i] - cost[i]);

    }

    if (total_sum < 0) {
        return -1;
    }

    int left_sum = 0;
    int right_sum = total_sum;
    int max_sum = total_sum;
    int index = 0;

    for (int j = 0; j < gas.size(); ++j) {

        left_sum += (gas[j] - cost[j]);
        right_sum = total_sum - left_sum;

        if (right_sum > max_sum) {
            max_sum = right_sum;
            index = j+1;
        }

    }

    return index;

}

int main() {

    vector<int>gas = {0, 2, 3, 4, 5,100};
    vector<int>cost = {30, 4, 5, 10, 20,1000};
    cout << "can complete : " << canCompleteCircuit(gas, cost);
    return 0;
}