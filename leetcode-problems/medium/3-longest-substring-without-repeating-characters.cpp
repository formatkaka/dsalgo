//
// Created by Siddhant on 2019-11-11.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int lengthOfLongestSubstring(string s) {

    int  global_max = 1;
//    vector<string> dp(s.length() + 1, "");
//    dp[0] = s[0];
    string local_max;
    local_max = s[0];
    for (int i = 1; i < s.length(); ++i) {
        int find = local_max.find(s[i]);

        if (find != string::npos) {
            local_max = local_max.substr(find+1) + s[i];
        }else{
            local_max = local_max + s[i];
        }

        global_max = max(global_max, (int) local_max.length());
        cout << "local max : " << local_max << endl;
    }
    cout << "done : " << global_max << endl;
    return global_max;
}

int main() {

    lengthOfLongestSubstring("abcabcbb");
    return 0;
}