//
// Created by Siddhant on 2019-11-06.
//

#include "iostream"
#include "vector"
#include "string"

#define I INT_MAX

using namespace std;

int cost[][8] =
        {{I, I,  I, I,  I, I,  I, I},
         {I, I, 25, I,  I, I, 5,  I},
         {I, 25, I, 12, I, I,  I, 10},
         {I, I, 12, I, 8,  I,  I, I},
         {I, I,  I, 8,  I, 16, I, 14},
         {I, I,  I, I, 16, I, 20, 18},
         {I, 5,  I, I,  I, 20, I, I},
         {I, I, 10, I, 14, 18, I, I}};


int near[8] = {I, I, I, I, I, I, I, I};

vector<vector<int>> mstEdges;

int primsMST() {

    // find smallest cost edge
    int smallestEdge = INT_MAX;
    int edgeStart = -1, edgeEnd = -1;
    for (int i = 1; i < 8; ++i) {

        for (int j = 1; j <= i; ++j) {

            if (cost[i][j] < smallestEdge) {
                smallestEdge = cost[i][j];
                edgeStart = i;
                edgeEnd = j;
            }

        }

    }

    near[edgeStart] = 0;
    near[edgeEnd] = 0;

    for (int k = 1; k < 8; ++k) {

        if (near[k] == 0) {
            continue;
        }

        if (cost[k][edgeStart] < cost[k][edgeEnd]) {
            near[k] = edgeStart;
        } else {
            near[k] = edgeEnd;
        }

    }

    mstEdges.push_back({edgeStart, edgeEnd});

    while (mstEdges.size() != 6) {

        int smallestEdge = INT_MAX, smallestVertex;
        for (int i = 1; i < 8; ++i) {
            if (near[i] == 0) {
                continue;
            }
            if (cost[i][near[i]] < smallestEdge) {
                smallestEdge = cost[i][near[i]];
                smallestVertex = i;
            }

        }

        mstEdges.push_back({smallestVertex, near[smallestVertex]});
        near[smallestVertex] = 0;

        for (int k = 1; k < 8; ++k) {

            if (near[k] == 0) {
                continue;
            }

            if (cost[k][near[k]] < cost[k][smallestVertex]) {
                near[k] = near[k];
            } else {
                near[k] = smallestVertex;
            }

        }

    }

    int minCost = 0;

    for (auto mstEdge = mstEdges.begin(); mstEdge != mstEdges.end(); ++mstEdge) {

        cout << (*mstEdge)[0] << ',' << (*mstEdge)[1] << ", cost : " << cost[(*mstEdge)[0]][(*mstEdge)[1]] << endl;
        minCost += cost[(*mstEdge)[0]][(*mstEdge)[1]];
    }

    return minCost;

}

int main() {

    cout << " mst cost is : " << primsMST();
    return 0;
}