//
// Created by Siddhant on 2019-11-17.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int countNumbersWithUniqueDigits(int n) {

    if (n ==0) {
        return 1;
    }

    int result = 10;
    int curr = 9;

    for (int i = 2; i <= n; i++) {
        curr = curr * (11 - i);
        cout << curr << endl;
        result += curr;
    }

    return result;

}

int main() {

    cout << countNumbersWithUniqueDigits(5);
    return 0;
}