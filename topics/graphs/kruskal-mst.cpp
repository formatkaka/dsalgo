//
// Created by Siddhant on 2019-11-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<vector<int>> edge = {{1, 2, 28},
                  {1, 6, 10},
                  {2, 3, 16},
                  {2, 7, 14},
                  {3, 4, 12},
                  {4, 5, 22},
                  {4, 7, 18},
                  {5, 6, 25},
                  {5, 7, 24}};
vector<int> included(edge.size(),0);
int vertices = 7;

int set[8] = {-1,-1,-1,-1,-1,-1,-1,-1}; // 6 = vertices - 1
int size[8] = {1,1,1,1,1,1,1,1}; //

vector<vector<int>> result;

int root(int vertex) {

//    int parent = set[vertex];
    while(set[vertex] > 0){
        vertex = set[vertex];
    }

    return vertex;
}

void setUnion(int v1, int v2) {

    int root1 = root(v1);
    int root2 = root(v2);

    if (size[root1] > size[root2]) {
        size[root1] = size[root1] + size[root2];
        set[root2] = root1;
    } else {
        size[root2] = size[root1] + size[root2];
        set[root1] = root2;
    }
}

bool setFind(int v1, int v2) {
    return root(v1) == root(v2);
}

int findShortestEdge(){

    int min = INT_MAX;
    int minIndex = -1;
    for (int i = 0; i < edge.size(); ++i) {
        if(included[i] == 0 && edge[i][2] < min){
            min = edge[i][2];
            minIndex = i;
        }
    }

    return minIndex;
}

int kruskalMinCost() {

    int v = 0;

    while(v < vertices-1){

        int e = findShortestEdge();

        if(e < 0){
            break;
        }

        if(setFind(edge[e][0], edge[e][1])){
            included[e] = 1;
            continue;
        }

        setUnion(edge[e][0], edge[e][1]);
        included[e] = 1;
        result.push_back(edge[e]);
        v++;
    }

}

int main() {

//    setUnion(1,2);
//    setUnion(3,4);
//    setUnion(1,3);
//
//    cout << "is root same : " << setFind(1,4) << endl;

    kruskalMinCost();

    for (auto res = result.begin(); res != result.end(); ++res) {

        for (auto r = (*res).begin(); r != (*res).end(); ++r) {
            cout << (*r) << ',';
        }

        cout << endl;

    }

    return 0;
}