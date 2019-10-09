//
// Created by Siddhant on 2019-10-09.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int optimalCost[1005] = {-1};

int minCostClimbingStairs(vector<int>& cost, int index){

    if(index > cost.size()-1){
        optimalCost[cost.size()] = 0;
        return 0;
    }

    if(optimalCost[cost.size() - index] > -1){
        return optimalCost[cost.size() - index];
    }

//    if(index == cost.size()-1){
//        return cost[index];
//    }


    int try1 = cost[index] + minCostClimbingStairs(cost, index+1);
    int try2 = index==cost.size()-1?0:cost[index+1] + minCostClimbingStairs(cost, index+2);

    int minimum = min(try1, try2);
    optimalCost[cost.size() - index] = minimum;
    return minimum;

}

int main(){

    vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
//    vector<int> cost{10, 15, 20};
    cout << "min cost is : " << minCostClimbingStairs(cost, 0);

    return 0;
}