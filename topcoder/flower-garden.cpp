//
// Created by Siddhant on 2019-11-25.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] > b[0];
}

class FlowerGarden {

public:
    vector<int> getOrdering(vector<int> height, vector<int> bloom, vector<int> wilt) {

        vector<vector<int>> data;

        for (int i = 0; i < height.size(); ++i) {
            vector<int> row;
            row.push_back(height[i]);
            row.push_back(bloom[i]);
            row.push_back(wilt[i]);
            data.push_back(row);
        }

        sort(data.begin(), data.end(), compare);



    }

};

int main() {

    FlowerGarden f;
    vector<int> height =  {3,2,5,4};
    vector<int> bloom = {1,2,11,10};
    vector<int> wilt = {4,3,12,13};
    f.getOrdering(height, bloom, wilt);
    return 0;
}