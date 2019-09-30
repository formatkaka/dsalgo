//
// Created by Siddhant on 2019-09-30.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int price[] = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};


int maxPriceTopDown(int l) {
    static int memoize[10] = {-1};

    if (l == 0) return 0;

    if (memoize[l - 1] > 0) return memoize[l-1];
    int maxPrice = INT_MIN;
    for (int i = 1; i < l; ++i) {
        maxPrice = std::max(maxPrice, price[i - 1] + maxPriceTopDown(l - i));
    }
    memoize[l-1] = maxPrice;
    return maxPrice;
}

int maxPriceBottomUp(int l){
    static int memoize[10] = {-1};
    memoize[0] = 0;
    cout << endl;
    for (int i = 1; i <= l; ++i) {
//        cout << "i : " << i << endl;
        int maxPrice = price[i-1];
        for (int j = 1; j < (i/2 +1); ++j) {
//            cout << "j - 1 : " << j-1 << "  i-j+1 : " << i-j << endl;
//            cout << "price[j-1] + memoize[i-j-1] : " << price[j-1] + memoize[i-j] << endl;
            maxPrice = std::max(maxPrice, price[j-1] + memoize[i-j]);
        }
//        cout << "maxPrice : " << maxPrice << endl << endl;
        memoize[i] = maxPrice;
    }

    return memoize[l];

}

int main() {

    int l;
    cout << "Enter l : ";
    cin >> l;
    cout << "max price is : " << maxPriceBottomUp(l);
    return 0;
}