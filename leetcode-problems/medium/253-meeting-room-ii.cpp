//
// Created by Siddhant on 2019-11-13.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include <queue>

using namespace std;

int minMeetingRooms(vector<vector<int>> &intervals) {

    //sort
    sort(intervals.begin(), intervals.end(),
         [](const std::vector<int> &a, const std::vector<int> &b) {
             return a[1] < b[1];
         });
    
    
    // divide in rooms
    priority_queue<int, std::vector<int>, greater<int> > min_heap;

    for (int i = 0; i < intervals.size(); ++i) {

        if(min_heap.empty()){
            min_heap.push(intervals[i][1]);
            continue;
        }

        int f = min_heap.top();

        if(f <= intervals[i][0]){
            min_heap.pop();
            min_heap.push(intervals[i][1]);
        }else{
            min_heap.push(intervals[i][1]);
        }


    }

    return min_heap.size();

}

int main() {

    vector<vector<int>> v = {{2,15},{36,45},{9,29},{16,23},{4,9}};
    cout << "min rooms required : " << minMeetingRooms(v);
    return 0;
}