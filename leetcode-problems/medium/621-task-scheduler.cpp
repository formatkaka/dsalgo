//
// Created by Siddhant on 2019-11-27.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"
#include "unordered_map"

using namespace std;
//
//bool comparator(const pair<int, char>& p1, const pair<int, char>& p2){
//    return p1.first > p2.first;
//}

class Compare
{
public:
//    bool operator() (Foo, Foo)
//    {
//        return true;
//    }

    bool operator () (const pair<int, char>& p1, const pair<int, char>& p2){
    return p1.first > p2.first;
}
};

int leastInterval(vector<char> &tasks, int n) {

    unordered_map<char, int> freq;
    priority_queue<pair<int, char>, vector<pair<int, char>>, Compare> q;

    for (int i = 0; i < tasks.size(); ++i) {
        freq[tasks[i]]++;
    }


    for (auto mapIterator = freq.begin(); mapIterator != freq.end(); ++mapIterator) {
        q.push(make_pair(-1, mapIterator->first));
    }

    int curr_time = 0;

    while (!freq.empty()) {

        pair<int, char> p = q.top();
        q.pop();

        if (p.first == -1) {
            // not yet initiated
            freq[p.second]--;
            p.first = curr_time;

            if (freq[p.second] > 0) {
                q.push(p);
            }else{
                freq.erase(p.second);
            }

        } else {

            if (curr_time - p.first > n) {
                freq[p.second]--;
                p.first = curr_time;

                if (freq[p.second] > 0) {
                    q.push(p);
                }else{
                    freq.erase(p.second);
                }
            }else{
                q.push(p);
            }

        }


        curr_time++;

    }

    return curr_time;

}

int main() {

    vector<char> tasks = {'A','A','A','B','B','B','C'};
    cout << "ans : " << leastInterval(tasks, 2);
    return 0;
}