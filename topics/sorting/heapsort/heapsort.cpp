//
// Created by Siddhant on 2019-11-24.
//

#include "heapsort.h"

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "queue"

using namespace std;

int main(){

    vector<int> v = {1,2,8,4,5,7};

    priority_queue<int, vector<int>, greater<int>> p;
    int k = 6;
    for (int i = 0; i < v.size(); ++i) {

        p.push(v[i]);
        if(p.size() > k){
            p.pop();
        }

    }

    cout << p.top() << endl;

    return 0;
}