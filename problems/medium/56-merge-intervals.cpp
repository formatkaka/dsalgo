//
// Created by Siddhant on 2019-11-11.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<vector<int>> mergeOld(vector<vector<int>> &intervals) {

    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0];
    });

    int localmin = intervals[0][0];
    int localmax = intervals[0][1];

    result.push_back({localmin, localmax});

    for (int i = 1; i < intervals.size(); i++) {

//        bool c1 = localmin >= intervals[i + 1][0] && localmin <= intervals[i + 1][1];
//        bool d1 = intervals[i + 1][0] >= localmin && intervals[i + 1][0] <= localmax;

        vector<int> l = result[result.size() - 1];
        bool c = l[1] < intervals[i][0];
        if (c){
            result.push_back(intervals[i]);
            continue;
        }

        result[result.size()-1][1] = max(l[1], intervals[i][1]);

//
//        cout << " c1 : " << intervals[i + 1][0] << " <= " << localmin << " <= " << intervals[i + 1][1] << endl;
//        cout << " d1 : " << localmin << " <= " << intervals[i + 1][0] << " <= " << localmax << endl;
//
//        if (c1 || d1) {
//            localmin = min(localmin, intervals[i + 1][0]);
//            localmax = max(localmax, intervals[i + 1][1]);
//        } else {
//            result.push_back({localmin, localmax});
//            localmin = intervals[i][0];
//            localmax = intervals[i][1];
//        }

    }

//    if(!intervals.empty() && result.empty()){
//    result.push_back({localmin, localmax});
//    }

    return result;

}
vector<vector<int>> merge(vector<vector<int>> &intervals) {

    vector<vector<int>> result;

    sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) {
        return a[0] < b[0];
    });


    for (int i = 0; i < intervals.size(); i++) {

        if (result.empty() || (result[result.size() - 1][1] < intervals[i][0])){
            result.push_back(intervals[i]);
            continue;
        }

        vector<int> l = result[result.size() - 1];
        result[result.size()-1][1] = max(l[1], intervals[i][1]);

    }

    return result;

}

int main() {

//    vector<vector<int>> v = {{2,6},{8,10},{1,18},{1,3}};
    vector<vector<int>> v = {{2,  6},
                             {1,  3},
                             {8,  10},
                             {15, 18}};
//    vector<vector<int>> v = {{1,4},{4,5}};
    merge(v);
    return 0;
}