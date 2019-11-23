//
// Created by Siddhant on 2019-11-22.
//

#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include "iostream"
#include "list"
#include "queue"
#include "unordered_set"
#include "unordered_map"

using namespace std;


template<class T>
class Graph {
    int V;
    unordered_map<T, vector<T>> l;

public:

    Graph(int v) {

        this->V = v;
//        this->l = new list<T>[v];

    }

    void addEdge(T v1, T v2) {

        if(l.find(v1) == l.end()){
            vector<T> temp;
            l[v1] = temp;
        }

        if(l.find(v2) == l.end()){
            vector<T> temp;
            l[v2] = temp;
        }

        l[v1].push_back(v2);
        l[v2].push_back(v1);

    }

    int shortestDistance(T n1, T n2) {

        queue<T> q;
        q.push(n1);
        unordered_set<T> visited;
        unordered_map<T, T> parent;
        visited.insert(n1);
        int val = 0;
        while (!q.empty()) {

            int q_size = q.size();

            while (q_size > 0) {
                T nodeval = q.front();
                q.pop();

                for (auto it = l[nodeval].begin(); it != l[nodeval].end(); ++it) {

                    if (visited.find(*it) == visited.end()) {
                        parent[*it] = nodeval;
                        visited.insert(*it);
                        q.push(*it);
                    }
//                    cout << *it << endl;
                    if (*it == n2) {

                        string h = *it;

                        cout << "Path : " << *it << " <-- ";

                        while(h != "0#0"){

                            cout << parent[h] << " <-- ";
                            h = parent[h];
                        }
                        cout << endl;
                        return val;
                    }

                }
                q_size--;
            }

            val++;

        }

        return -1;

    }

};

#endif //DSALGO_GRAPH_H
