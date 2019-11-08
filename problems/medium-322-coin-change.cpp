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



void coinChange(vector<int>& coins, int amount, int numOfCoins){

    static vector<int> mem(amount+1, amount+1);

    if(mem[amount] < amount+1){
        return;
    }

    if(amount == 0){
        found = true;
        minCoins = min(numOfCoins, minCoins);
        return;
    }

    if(coins.empty()){
        return;
    }

    vector<int> newCoins(coins.begin(), coins.end()-1);
    int maxFactor = (amount / coins[coins.size()-1]);

    for (int i = 0; i <= maxFactor; ++i) {
        int z = numOfCoins+i;
        int y = amount - (coins[coins.size()-1]*i);

        if(y == 0){
            mem[amount] = min(mem[amount], z);
        }

        coinChange(newCoins, y, z);
    }

}

int main(){

    vector<int> coins = {1,2,5};
    int amount = 11;
//    vector<int> coins = {};
//    int amount = 3;
    coinChange(coins, amount, 0);
    int result = found?minCoins:-1;
    cout << "min coins required : " << result;
    return 0;
}