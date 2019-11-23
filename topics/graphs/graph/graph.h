//
// Created by Siddhant on 2019-11-22.
//

#ifndef DSALGO_GRAPH_H
#define DSALGO_GRAPH_H

#include "iostream"
#include "vector"
#include "list"
#include "queue"
#include "unordered_set"
#include "unordered_map"

using namespace std;
//
//class graph {
//    int V;
//    list<int>* l;
//public:
//    graph(int V)
//    {
//        this->V = V;
//        l = new list<int>[V];
//    }
//    void addEdge(int V1, int V2)
//    {
//        l[V1].push_back(V2);
//        l[V2].push_back(V1);
//    }
//    int bfs(int in1, int in2);
//};

template<class T>
class graph {
    int V;
    int type = 0;
    unordered_map<T, vector<T>> l;
    unordered_map<T, int> dist;
    bool cycleExists = false;
    vector<T> topSort;

public:
    graph(int v, int type) {


        // type 0 -> undir
        // type 1 -> dir

        V = v;
        this->type = type;

    }

    void addEdge(T v1, T v2) {
        l[v1].push_back(v2);

        if (type == 1) return;
        l[v2].push_back(v1);
    }

    void bfs(int v) {

        queue<int> q;
        q.push(v);

        unordered_set<int> visited;
        visited.insert(v);

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            for (auto it = l[node].begin(); it != l[node].end(); ++it) {

                if (visited.find(*it) == visited.end()) {

                    visited.insert(*it);
                    q.push(*it);
                }

            }


        }

    }

    bool isdag() {

        // check if there is a cycle. using dfs , try to find any back edges

        if (type == 0) {
            return false;
        }

        dfs();

        cout << "cycle exists : " << cycleExists << endl;

    }

    void dfs() {

        vector<int> back(this->V, -1);

        for (int i = 0; i < this->V; ++i) {

            // mark parent null
            if (this->dist.find(i) == this->dist.end()) {
                this->dist[i] = -1;
                dfsVisit(i, back);
            }
        }

    }

    void dfsVisit(T v, vector<int> &back) {

        back[v] = 0;

        for (int i = 0; i < l[v].size(); ++i) {

            T node = l[v][i];

            if (back[node] == 0) {
                cycleExists = true;
            }

            if (this->dist.find(node) == this->dist.end()) {
                this->dist[node] = v;
                dfsVisit(node, back);
            }

        }
        topSort.push_back(v);
        back[v] = -1;

    }

    vector<T> gettopsort() {

        dfs();

        if (cycleExists) {
            vector<T> temp = {};
            return temp;
        }

        reverse(topSort.begin(), topSort.end());
        return topSort;

    }

};


#endif //DSALGO_GRAPH_H
