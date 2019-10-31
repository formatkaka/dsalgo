//
// Created by Siddhant on 2019-10-18.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int smallestRangeI(vector<int> &A, int K) {
    if (A.size() < 2) return 0;

    int max = *std::max_element(begin(A), end(A));
    int min = *std::min_element(begin(A), end(A));

    int diff = (max - min) - 2 * K;
//    cout << "max : " << max << endl;
//    cout << "min : " << min << endl;
    cout << "diff : " << diff << endl;
    if (diff <= 0) {
        return 0;
    } else {
        return diff;
    }

}

int main() {

    vector<int> v = {1,3,4,7,6,4,3,2,8};
    cout << "Ans : " << smallestRangeI(v, 3);
    return 0;
}
