//
// Created by Siddhant on 2019-11-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

//int maxProfit(vector<int> &prices) {
//
//    int newlow = prices[0], newhigh = 0;
//    int profit = 0;
//    for (int i = 1; i < prices.size() - 1; ++i) {
//
//        int gp = prices[i] - prices[i - 1];
//        int gc = prices[i + 1] - prices[i];
//
//        if (gp * gc > 0) {
//
//            if (gc < 0) {
//                newlow = prices[i];
//            } else {
//                newhigh = prices[i];
//            }
//
//        } else {
//
//            if (gc > 0) {
//                profit += (newhigh - newlow);
//            } else {
//                newlow = prices[i];
//            }
//
//        }
//
//    }
//
//    if (prices[prices.size() - 1] > newlow) {
//        profit += (newhigh - newlow);
//    }
//
//    return profit;
//
//}

int maxProfit(vector<int> &prices) {

    int newlow = prices[0], newhigh = 0;
    int profit = 0;
    for (int i = 1; i < prices.size(); ++i) {

        if(prices[i] > prices[i-1] && (i ==prices.size()-1 || ( i < prices.size()-1 && prices[i]>=prices[i+1]) ) ){
            profit += (prices[i]-newlow);

            if(i < prices.size()-1){
                newlow = prices[i+1];
            }

        }

        if(prices[i] < prices[i-1]){
            newlow = prices[i];
        }

    }

    return profit;

}

int main() {

//    vector<int> v = {0,5,5,6,2,1,1,3};
    vector<int> v = {5,2,3,2,6,6,2,9,1,0,7,4,5,0};
    cout << "maxprofit : " << maxProfit(v);
    return 0;
}