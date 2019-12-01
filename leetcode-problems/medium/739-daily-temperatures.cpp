//
// Created by Siddhant on 2019-11-28.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"
#include "unordered_map"

using namespace std;

vector<int> dailyTemperatures(vector<int> &T) {

    vector<int> res;

    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> m;

    for (int i = 0; i < T.size(); ++i) {

        m[T[i]].push(i);

    }

    for (int day_num = 0; day_num < T.size(); ++day_num) {

        int today_temp = T[day_num];
        int min_days_to_rise = INT_MAX;
        // remove from pq
        m[today_temp].pop();

        for (int k = T[day_num]+1; k < 101; ++k) {

            if(m.find(k) == m.end()){
                continue;
            }

            if(m[k].size() == 0){
                m.erase(k);
                continue;
            }

            int higher_temp_smallestday = m[k].top();

            if(higher_temp_smallestday < min_days_to_rise){
                min_days_to_rise = higher_temp_smallestday;
            }

        }

        if(min_days_to_rise == INT_MAX){
            res.push_back(0);
        }else{
            res.push_back(min_days_to_rise - day_num);
        }

    }

    return res;

}

int main() {

    vector<int> T = {90,91,73, 74, 75, 71, 69, 72, 76, 73};
    dailyTemperatures(T);
    return 0;
}