//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:

    int lcs(string& text1, int i, int j, vector<vector<int>> &dp){

        if(i < 0 || j > text1.length()-1){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(text1[i] == text1[j]){
            return dp[i][j] = 1 + lcs(text1, i-1, j+1, dp);
        }

        int m = max(lcs(text1, i-1, j, dp), lcs(text1, i, j+1, dp));
        dp[i][j] = m;
        return m;

    }

    int longestPalindromeSubseq2(string s) {

        vector<vector<int>> dp(1001, vector<int> (1001, -1));
        vector<vector<int>> dup = dp;
        int res = INT_MIN;
         for(int i = 0; i < s.length()-1; i++){

            int len1 = 1+2*lcs(s, i-1, i+1, dup);
            dup = dp;
            int len2 = INT_MIN;

            if(s[i] == s[i+1]){
                len2 = 2+2*lcs(s, i-1, i+2, dup);
                dup = dp;
            }

            res = max(res, max(len1, len2));

        }

        return res;

    }

    int find(string &s, int i, int j, vector<vector<int>>& dp ){

        if(i == j){
            return 1;
        }

        if(i > j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == s[j]){
            return dp[i][j] = 2+find(s, i+1, j-1, dp);
        }

        int l1 = find(s, i+1, j, dp);
        int l2 = find(s, i, j-1, dp);

        dp[i][j] = max(l1, l2);
        return dp[i][j];


    }

    int longestPalindromeSubseq(string s) {

        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        return find(s, 0, s.length()-1, dp);
    }

};

int main(){


    return 0;
}