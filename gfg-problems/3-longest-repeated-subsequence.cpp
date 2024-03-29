//
// Created by Siddhant on 2019-11-26.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

// DFFGGD

//int find(string s, int index, int count, vector<int>& dp){
//
//    if(index >= s.length()-1){
//        return count;
//    }
//
//    if(dp[index] != -1){
//        return dp[index];
//    }
//
//    int collision = -1;
//
//    for (int i = index+1; i < s.length(); ++i) {
//        if(s[i] == s[index]){
//            collision = i;
//            break;
//        }
//    }
//
//    int collidedNum = collision > -1 ? find(s, collision+1, count+1, dp) : 0; // 0 subseq if no collision
//
//    int withoutCollision = find(s, index+1, count, dp);
//
//    int m = max(collidedNum, withoutCollision);
//    dp[index] = m;
//    return m;
//
//}

int find(string s, int pt1, int pt2, vector<vector<int>>& dp){

    if(pt1 > s.length()-1 || pt2 > s.length()-1){
        return 0;
    }

    if(dp[pt1][pt2] != -1){
        return dp[pt1][pt2];
    }

    int collision = -1;

    for (int i = pt2; i < s.length(); ++i) {
        if(s[i] == s[pt1]){
            collision = i;
            break;
        }
    }

    int collidedNum = collision > -1 ? find(s, pt1+1, collision+1, dp)+1 : 0; // 0 subseq if no collision

    int withoutCollision1 = find(s, pt1+1, pt2, dp);
    int withoutCollision2 = find(s, pt1, pt2+1, dp);

    int m = max({collidedNum, withoutCollision1, withoutCollision2});
    dp[pt1][pt2] = m;
    return m;

}

int LRS(string s){
    vector<vector<int>> dp(s.length()+1, vector<int>(s.length()+1, -1));
    int ans = find(s, 0, 1, dp);
    return ans;
}

int main(){

//    cout << LRS("wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmcoqhnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcacehchzvfrkmlnozjkpqpxrjxkitzyxacbhhkicqcoendtomfgdwdwfcgpxiqvkuytdlcgdewhtaciohordtqkvwcsgspqoqmsboaguwnnyqxnzlgdgwpbtrwblnsadeuguumoqcdrubetokyxhoachwdvmxxrdryxlmndqtukwagmlejuukwcibxubumenmeyatdrmydiajxloghiqfmzhlvihjouvsuyoypayulyeimuotehzriicfskpggkbbipzzrzucxamludfykgruowzgiooobppleqlwphapjnadqhdcnvwdtxjbmyppphauxnspusgdhiixqmbfjxjcvudjsuyibyebmwsiqyoygyxymzevypzvjegebeocfuftsxdixtigsieehkchzdflilrjqfnxztqr");
    cout << LRS("ababdd");
    return 0;
}