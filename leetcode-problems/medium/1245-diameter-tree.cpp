//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "queue"

using namespace std;

class graph {
public:

    unordered_map<int, vector<int>> g;

    graph() {};

    void addedge(int v1, int v2) {

        g[v1].push_back(v2);
        g[v2].push_back(v1);

    }

    pair<int, int> bfsGetMaxDistNode(int v){

        queue<int> q;
        q.push(v);
        unordered_map<int, int> visited;
        int d = 0;
        int maxDist = INT_MIN, maxNode = -1;
        visited.insert(make_pair(v, 0));
        while(!q.empty()){

            int qsize = q.size();
            d++;
            while(qsize > 0){

                int node = q.front();
                q.pop();

                for (int i = 0; i < g[node].size(); ++i) {

                    if(visited.find(g[node][i]) == visited.end()){

                        visited.insert(make_pair(g[node][i], d));
                        if(d > maxDist){
                            maxDist = d;
                            maxNode = g[node][i];
                        }
                        q.push(g[node][i]);

                    }

                }

                qsize--;
            }

        }

        cout << "maxNode : " << maxNode << endl;
        cout << "maxDist : " << maxDist;

        return make_pair(maxNode, maxDist);
    }

};


int treeDiameter(vector<vector<int>> &edges) {

    graph g;
    for (int i = 0; i < edges.size(); ++i) {

        g.addedge(edges[i][0], edges[i][1]);

    }

    int start_edge = 0;

    pair<int, int> max1 = g.bfsGetMaxDistNode(start_edge);


    pair<int, int> m = g.bfsGetMaxDistNode(max1.first);

    cout << "maxDist : " << m.second << " from : " << max1.first << " to : " << m.first << endl;
    return m.second;
}

int main() {

//    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{1,4},{4,5},{3,6}};
    vector<vector<int>> edges = {{0,1},{0,2},{2,3}};
    treeDiameter(edges);

    return 0;
}