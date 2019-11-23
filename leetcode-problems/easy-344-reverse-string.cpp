//
// Created by Siddhant on 2019-10-31.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void reverseString(vector<char>& s) {

    int start = 0;
    int end = s.size()-1;

    while(end > start){

        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;

    }

}

int main(){


    vector<char> s = {};
    reverseString(s);

    for (auto ch = s.begin(); ch != s.end(); ++ch) {
        cout << *ch << ' ';
    }

    return 0;
}