//
// Created by Siddhant on 2019-11-24.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

int find(vector<int> &squares, vector<int> &dp, int n) {

    if (n == 0) {
        return 0;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    int ans = INT_MAX;

    for (int sq = 0; sq < squares.size(); sq++) {
        if (squares[sq] > n) {
            break;
        }
        int num = 1 + find(squares, dp, n - squares[sq]);
        ans = min(ans, num);
    }

    dp[n] = ans;
    return ans;

}

int numSquares(int n) {
    vector<int> squares = {}, dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i < sqrt(n) + 1; i++) {
        squares.push_back(i * i);
    }
    return find(squares, dp, n);
}

int main() {

    cout << numSquares(100);
    return 0;
}