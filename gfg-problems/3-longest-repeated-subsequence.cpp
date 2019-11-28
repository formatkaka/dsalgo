//
// Created by Siddhant on 2019-11-26.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int find(string s, int index, int count, vector<int>& dp){

    if(index >= s.length()-1){
        return count;
    }

    if(dp[index] != -1){
        return dp[index];
    }

    int collision = -1;

    for (int i = index+1; i < s.length(); ++i) {
        if(s[i] == s[index]){
            collision = i;
            break;
        }
    }

    int collidedNum = collision > -1 ? find(s, collision, count+1, dp) : -1;

    int withoutCollision = find(s, index+1, count, dp);

    int m = max(collidedNum, withoutCollision);
    dp[index] = m;
    return m;

}

int LRS(string s){
    vector<int> dp(s.length()+1, -1);
    int ans = find(s, 0, 0, dp);
    return ans;
}

int main(){

    cout << LRS("abcd");
    return 0;
}