//
// Created by Siddhant on 2019-11-16.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;


string encode(int num) {
    
    int len = (int) log2(num+1); 
    int start = (int) pow(2, len) - 1;
    
    int modifiedNum = num - start;
    
    string result = "";

    while(modifiedNum > 0){

        result += to_string(modifiedNum%2);
        modifiedNum = modifiedNum/2;

    }

//    cout << len - result.length();

    string s(len - result.length(), '0');
    result = result+s;
    reverse(result.begin(), result.end());

    return result;
}

int main() {

    cout << encode(0);
    return 0;
}