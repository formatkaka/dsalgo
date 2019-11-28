//
// Created by Siddhant on 2019-11-26.
//

#include "iostream"
#include "vector"
#include "string"
#include "map"

using namespace std;

int largestRectangleArea(vector<int> &heights) {

    map<int, int> m;

    for (int i = 0; i < heights.size(); ++i) {
        m[heights[i]]++;
    }

    int start = 0;
    int end = heights.size() - 1;
    int maxArea = 0;

//    for (auto mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator) {
//        cout << (*mapIterator).first << "  : " << (*mapIterator).second << endl;
//    }

    while (start <= end) {

        auto it = m.begin();

        maxArea = max((end - start + 1) * (it->first), maxArea);


        if (heights[start] > heights[end]) {
            int h = heights[end];
            if (m[h] == 1) {
                m.erase(h);
            } else {
                m[h]--;
            }
//
//            for (auto mapIterator = m.begin(); mapIterator != m.end(); ++mapIterator) {
//                cout << (*mapIterator).first << "  : " << (*mapIterator).second << endl;
//            }
            cout << endl;
            end--;
            continue;
        }

        int h = heights[start];
        if (m[h] == 1) {
            m.erase(h);
        } else {
            m[h]--;

        }

        start++;


    }

    return maxArea;

}

int main() {

    vector<int> hist = {6, 7, 1, 5};
    cout << largestRectangleArea(hist);
    return 0;
}