//
// Created by Siddhant on 2019-11-06.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

//int coinChange(vector<int>& coins, int amount) {
//
//    sort(coins.begin(), coins.end());
//    int minCoins = INT_MAX, zeroFound = false;
//
//    for (int j = coins.size()-1; j >= 0 ; --j) {
//
//        int numOfCoins = 0;
//        int amt = amount;
//        for (int i = j; i >= 0 ; ) {
//
//            if(amt == 0){
//                zeroFound = true;
//                minCoins = min(numOfCoins, minCoins);
//            }
//
//            if(amt >= coins[i]){
//                amt -= coins[i];
//                numOfCoins++;
//                continue;
//            }
//
//            i--;
//
//        }
//    }
//
//
//    return zeroFound ? minCoins : -1;
//}

int minCoins = INT_MAX;
int found = false;


void coinChange(vector<int> &coins, int amount) {

    vector<int> v(amount + 1, INT_MAX);
    int numOfCoins = coins.size();
    v[0] = 0;
    for (int i = 0; i <= amount; ++i) {
        for (int j = 0; j < numOfCoins; ++j) {

            if (i - coins[j] >= 0) {
                v[i] = min(v[i], 1 + v[i - coins[j]]);
            }

        }

    }

    cout << "min amount is : " << v[amount];

}

int main() {

    vector<int> coins = {1, 2, 5};
    int amount = 11;
//    vector<int> coins = {};
//    int amount = 3;
    coinChange(coins, amount);
//    int result = found?minCoins:-1;
//    cout << "min coins required : " << result;
    return 0;
}