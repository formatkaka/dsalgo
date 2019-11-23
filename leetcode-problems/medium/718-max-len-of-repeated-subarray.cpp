//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    int find(vector<int>& A, vector<int>& B, int i, int j, int count, vector<vector<int>>& dp){
        if(i < 0 || j < 0){
            return count;
        }

        int len = count;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        // dp[i][j] = 0;

        if(A[i] == B[j]){
            len =  find(A, B, i-1, j-1, count+1,dp);
        }

        int len1 = find(A, B, i-1, j, 0,dp);
        int len2 = find(A, B, i, j-1, 0,dp);

        int m = max({len, len1, len2});

        dp[i][j] = m;

        return m;

    }

    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size(), vector<int> (B.size(), -1));
        find(A,B,A.size()-1, B.size()-1,0, dp);
        return dp[A.size()-1][B.size()-1];
    }
};

int main(){


    return 0;
}