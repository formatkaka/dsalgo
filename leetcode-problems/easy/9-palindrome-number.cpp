//
// Created by Siddhant on 2019-11-21.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

bool isPalindrome(int x) {

    // single digit and negative inputs
    if (x < 0) {
        return false;
    }

    if (x / 10 == 0) {
        return true;
    }

    int num_of_digits = (int) log10(x);

    int left = pow(10, num_of_digits);
    int right = 10;

    for (int i = 0; i < (num_of_digits+1) / 2; ++i) {

//        num_of_digits = (int) log10(x);
//
//        left = pow(10, num_of_digits);

        int left_num = x / left;
        int right_num = x % right;

        if (left_num != right_num) {
            return false;
        }

        x = x - left_num * left;
        x = (x - right_num) / 10;

        left /= 100;

    }

    return true;
}

int main() {

    cout << isPalindrome(19);
    return 0;
}