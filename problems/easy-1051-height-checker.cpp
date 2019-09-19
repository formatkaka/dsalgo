//
// Created by Siddhant on 2019-09-19.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int heightChecker(vector<int>& heights) {

    vector<int> heightsSorted = heights;
    sort(heightsSorted.begin(), heightsSorted.end());
    int numOutOfOrder = 0;
    for (int i = 0; i < heights.size(); ++i) {
        if(heightsSorted[i] != heights[i]) numOutOfOrder++;
    }

    return numOutOfOrder;

}

int main(){

    vector<int> heights = {1,1,4,2,1,3};
    cout << "Ans : " << heightChecker(heights);
    return 0;
}