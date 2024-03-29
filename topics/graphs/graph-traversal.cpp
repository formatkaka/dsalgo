//
// Created by Siddhant on 2019-11-02.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"
#include "stack"

using namespace std;

void dfsRecursive(vector<vector<int>>& G, int start){

    static vector<int> visitedVertexes(G.size(), 0);

    if(!visitedVertexes[start]){

        cout << start << ',';
        visitedVertexes[start] = 1;

        for (int i = 1; i < G[start].size(); ++i) {

            if(G[start][i] == 1 && !visitedVertexes[i]){
                dfsRecursive(G, i);
            }
        }

    }

}

void dfs(vector<vector<int>>& G){

    stack<int> dfsStack;
    vector<int> visitedVertexes(G.size(), 0);

    dfsStack.push(1);
    visitedVertexes[1] = 1;
    cout << "dfs : " ;

    while(!dfsStack.empty()){

        int parentIndex = dfsStack.top();
        dfsStack.pop();
        cout << parentIndex << ',';

        for (int i = G[parentIndex].size() - 1; i >= 1; --i) {

            if(G[parentIndex][i] == 1 && !visitedVertexes[i]){
                dfsStack.push(i);
                visitedVertexes[i] = 1;
            }

        }

    }
    cout << endl;

}

void bfs(vector<vector<int>>& G){

    queue<int> bfsQueue;
    vector<int> visitedVertexes(G.size(), 0);
    bfsQueue.push(1);
    visitedVertexes[1] = 1;
    cout << "bfs : " ;
    while(!bfsQueue.empty()){

        int parentIndex = bfsQueue.front();
        bfsQueue.pop();
        cout << parentIndex  << ',';
        for (int i = 1; i < G[parentIndex].size(); ++i) {

            if(G[parentIndex][i] == 1 && !visitedVertexes[i]){
                bfsQueue.push(i);
                visitedVertexes[i] = 1;
            }

        }

    }

    cout << endl;

}

int main(){

    vector<vector<int>>G =  {{0,0,0,0,0,0,0},
                             {0,0,1,1,0,0,0},
                             {0,1,0,0,1,0,0},
                             {0,1,0,0,1,0,0},
                             {0,0,1,1,0,1,1},
                             {0,0,0,0,1,0,0},
                             {0,0,0,0,1,0,0}};
    bfs(G);
    dfs(G);
    cout << "dfs recursive : ";
    dfsRecursive(G,1);

    return 0;
}