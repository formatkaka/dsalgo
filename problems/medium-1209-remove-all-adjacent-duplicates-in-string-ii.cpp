//
// Created by Siddhant on 2019-10-18.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool CheckPrevKChars(string res, int k, char S){

    int len = res.length();
    for (int i = len-1; i > len-1-(k-1) ; --i) {
        if(res[i] != S){
            return false;
        }
    }

    return true;

}

string removeDuplicates(string S, int k) {

    vector<pair<char, int>> st = {make_pair('0', 1)};

    for (int i = 0; i < S.length(); ++i) {

        if(st.back().first != S[i] ){
            st.push_back(make_pair(S[i], 1));
            continue;
        }

        if(st.back().first == S[i]){
            st.back().second++;
        }

        if(st.back().second == k){
            st.pop_back();
        }

    }
    string res = "";

    for (int j = 0; j < st.size(); ++j) {
        res += string(st[j].second, st[j].first);
    }

    return res.substr(1);

}

int main(){

    string S = "deeedbbcccbdaa";
    cout << "ans is : " << removeDuplicates(S, 3);
    return 0;
}