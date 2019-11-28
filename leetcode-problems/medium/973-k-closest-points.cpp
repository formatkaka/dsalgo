//
// Created by Siddhant on 2019-11-25.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"
#include "cmath"

using namespace std;

class Compare
{
public:
    bool operator() (const pair<double, vector<int>>& a, const pair<double, vector<int>>& b)
    {
        return a.first < b.first;
    }
};


vector<vector<int>> kClosest(vector<vector<int>> &points, int K) {

    priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, Compare> p;

    vector<vector<int>> res;

    for (int i = 0; i < points.size(); ++i) {
        double sq =  pow(points[i][0], 2) + pow(points[i][1],2);
        double d = sqrt(sq);

        p.push(make_pair(d, points[i]));

        if(p.size() > K){
            p.pop();
        }

    }

    while(p.size() > 0){
        res.push_back(p.top().second);
        //        cout << p.top().second[0] << " " << p.top().second[1] << endl;
        p.pop();
    }

    return res;

}

int main() {

    vector<vector<int>> pts = {{3,3},{5,-1},{-2,4},{1,1},{2,3}, {0,1}};
    kClosest(pts, 2);
    return 0;
}