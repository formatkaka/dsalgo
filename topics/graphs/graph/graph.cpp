//
// Created by Siddhant on 2019-11-22.
//

#include "graph.h"

#include "iostream"
#include "vector"
#include "string"

#include "list"

using namespace std;

int main() {

    graph<int> g(2, 1);

    g.addEdge(0, 1);
//    g.addEdge(0,1);
//    g.addEdge(2,2);
//    g.addEdge(4,0);
//    g.addEdge(0,1);

//    g.isdag();

    vector<int> k = g.gettopsort();
    cout << "topsort : " << endl;
    for (int i = 0; i < k.size(); ++i) {
        cout << k[i] << ", ";
    }
//    g.bfs(1);

    return 0;
}