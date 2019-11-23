//
// Created by Siddhant on 2019-11-18.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int find(string &s, int start, int end, int count){

    if(start == end){
        return count;
    }

    if(start > end){
        return count;
    }

    if(end == start+1 && s[start] == '(' && s[end] == ')'){
        return 2;
    }

    int len1 = count;

    if(s[start] == '(' && s[end] == ')'){
        len1 = find(s, start+1, end-1, count+1);

        int len4 = 0, len5 = 0;

        if(s[start+1] == ')'){
            len4 = find(s, start+2, end, count+2);
        }

        if(s[end-1] == '('){
            len5 = find(s, start, end-2, count+2);
        }

        len1 = max({len1, len4, len5});

    }

    int len2 = find(s, start+1, end, 0);
    int len3 = find(s, start, end-1, 0);

    int maxLen = max({len1, len2, len3});

    return maxLen;

}

int longestValidParentheses(string s) {

    return find(s, 0, s.length()-1, 0);

}

int main() {

    cout << longestValidParentheses("()()");
    return 0;
}