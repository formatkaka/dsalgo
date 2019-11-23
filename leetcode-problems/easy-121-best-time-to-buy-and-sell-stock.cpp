//
// Created by Siddhant on 2019-10-17.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int maxProfit(vector<int>& prices) {

    if(prices.size() < 2) return 0;

    int maxProfit = 0;
    int smallest = prices[0];

    for (int i = 0; i < prices.size(); ++i) {

        if(prices[i] < smallest){
            smallest = prices[i];
            continue;
        }

        int profit = prices[i] - smallest;
        maxProfit = maxProfit > profit ? maxProfit : profit;
    }

    return maxProfit;

}

int main(){

    vector<int> prices = {1};

    cout << "max profit is : " << maxProfit(prices);

    return 0;
}