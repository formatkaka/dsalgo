//
// Created by Siddhant on 2019-10-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool checkSubstr(string haystack, string needle, int index){

    for (int i = index+1, j=1; i < index+needle.length() ; ++i,++j) {
        if(haystack[i]!=needle[j]){
            return false;
        }
    }

    return true;

}

int strStr(string haystack, string needle) {

    if(needle.length() == 0){
        return 0;
    }

    // Missed this edge case
    if(needle.length() > haystack.length()){
        return -1;
    }

    for (int i = 0; i < haystack.length()-needle.length()+1; ++i) {

        if(haystack[i]==needle[0]){
            if(checkSubstr(haystack, needle, i)){
                return i;
            }
        }

    }

    return -1;

}

int main(){

    cout << "index is : " << strStr("hello", "ok");
    return 0;
}