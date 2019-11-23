//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int nthUglyNumber(int n) {

    if(n == 0){
        return 0;
    }

    vector<int> nums(n, 1);

    int i2 = 0, i3 = 0, i5 = 0;
    int m2 = 2, m3 = 3, m5 = 5;

    for (int i = 1; i < n; ++i) {

        int min_num = min({m2, m3, m5});
        nums[i] = min_num;

        if(min_num == m2){
            i2++;
            m2 = nums[i2]*2;
        }

        if(min_num == m3){
            i3++;
            m3 = nums[i3]*3;
        }

        if(min_num == m5){
            i5++;
            m5 = nums[i5]*5;
        }

    }

    return nums[n-1];

}

int main() {

    cout << nthUglyNumber(1);
    return 0;
}