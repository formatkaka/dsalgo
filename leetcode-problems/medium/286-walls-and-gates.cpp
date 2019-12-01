//
// Created by Siddhant on 2019-11-30.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int explore(vector<vector<int>> &rooms, int i, int j) {

    cout << "i : " << i << " , j : " << j << endl;

    int top_dist = INT_MAX, left_dist = INT_MAX, right_dist = INT_MAX, bottom_dist = INT_MAX;

    if (i > 0) {

        int top = rooms[i - 1][j];

        if (top == 0) {
            rooms[i][j] = 1;
            return 1;
        }

        if (top == INT_MAX) {
            rooms[i][j] = -1;
            top_dist = explore(rooms, i - 1, j);
            rooms[i][j] = INT_MAX;
        }

        if (top > 0 && top < INT_MAX) {
            top_dist = top;
        }

    }

    if (j > 0) {
        int left = rooms[i][j - 1];

        if (left == 0) {
            rooms[i][j] = 1;
            return 1;
        }

        if (left == INT_MAX) {
            rooms[i][j] = -1;
            left_dist = explore(rooms, i, j - 1);
            rooms[i][j] = INT_MAX;
        }

        if (left > 0 && left < INT_MAX) {
            left_dist = left;
        }
    }

    if (i < rooms.size() - 1) {
        int bottom = rooms[i + 1][j];

        if (bottom == 0) {
            rooms[i][j] = 1;
            return 1;
        }

        if (bottom == INT_MAX) {
            rooms[i][j] = -1;
            bottom_dist = explore(rooms, i + 1, j);
            rooms[i][j] = INT_MAX;
        }

        if (bottom > 0 && bottom < INT_MAX) {
            bottom_dist = bottom;
        }
    }

    if (j < rooms[0].size() - 1) {
        int right = rooms[i][j + 1];

        if (right == 0) {
            rooms[i][j] = 1;
            return 1;
        }

        if (right == INT_MAX) {
            rooms[i][j] = -1;
            right_dist = explore(rooms, i, j + 1);
            rooms[i][j] = INT_MAX;
        }

        if (right > 0 && right < INT_MAX) {
            right_dist = right;
        }
    }

    int min_dist = min({right_dist, left_dist, top_dist, bottom_dist});

    if (min_dist == INT_MAX) {
//        rooms[i][j] = -2;
        return min_dist;
    }

//    rooms[i][j] = min_dist + 1;
    return min_dist + 1;

}

void wallsAndGates(vector<vector<int>> &rooms) {

    for (int i = 0; i < rooms.size(); ++i) {
        for (int j = 0; j < rooms[i].size(); ++j) {
            if (rooms[i][j] == INT_MAX) {
                rooms[i][j] = explore(rooms, i, j);
            }
        }
    }

    cout << "done";

}

int main() {

    vector<vector<int>> v = {{2147483647, -1,         0,          2147483647},
                             {2147483647, 2147483647, 2147483647, -1},
                             {2147483647, -1,         2147483647, -1},
                             {0,          -1,         2147483647, 2147483647}};

    vector<vector<int>> k = {{-1,         0,          2147483647, 2147483647, 0,  0,          2147483647, 2147483647, -1,         0,          0,  -1,         -1,         2147483647, -1,         -1,         2147483647, 2147483647, 2147483647, 0,          0,          -1,         2147483647, -1,         -1,         -1,         0,          2147483647, 0,          0,          0,  -1,         2147483647, 0,          0,          2147483647, -1,         -1,         0,          0,          -1,         0,          2147483647, 2147483647, -1,         2147483647},
                             {0,          -1,         0,          -1,         0,  0,          0,          -1,         -1,         0,          -1, 2147483647, 2147483647, -1,         2147483647, -1,         2147483647, -1,         -1,         2147483647, 0,          -1,         2147483647, 0,          2147483647, 0,          -1,         2147483647, 0,          -1,         -1, 2147483647, 0,          2147483647, 0,          2147483647, -1,         2147483647, 2147483647, 2147483647, -1,         0,          -1,         2147483647, 0,          2147483647},
                             {2147483647, -1,         -1,         2147483647, 0,  0,          0,          2147483647, -1,         0,          -1, -1,         2147483647, 2147483647, 2147483647, 2147483647, -1,         2147483647, 0,          0,          2147483647, 0,          -1,         0,          0,          2147483647, 2147483647, 0,          0,          2147483647, -1, -1,         0,          2147483647, 0,          2147483647, -1,         -1,         2147483647, 2147483647, 0,          -1,         2147483647, -1,         -1,         -1},
                             {2147483647, -1,         -1,         2147483647, 0,  -1,         -1,         -1,         -1,         -1,         0,  -1,         -1,         2147483647, 0,          -1,         -1,         -1,         2147483647, 2147483647, -1,         2147483647, -1,         -1,         -1,         0,          -1,         -1,         0,          -1,         0,  -1,         2147483647, 2147483647, 2147483647, 2147483647, 2147483647, 0,          0,          2147483647, 2147483647, 2147483647, 2147483647, 0,          2147483647, 2147483647},
                             {2147483647, 2147483647, 2147483647, -1,         -1, 2147483647, 2147483647, -1,         0,          2147483647, -1, 0,          0,          2147483647, 2147483647, 0,          2147483647, -1,         -1,         2147483647, 0,          0,          0,          -1,         2147483647, 0,          2147483647, -1,         2147483647, 0,          0,  -1,         0,          2147483647, -1,         0,          -1,         -1,         2147483647, -1,         0,          0,          -1,         -1,         -1,         -1},
                             {-1,         -1,         2147483647, 2147483647, 0,  2147483647, 0,          0,          2147483647, 2147483647, 0,  -1,         0,          2147483647, -1,         2147483647, 2147483647, 0,          2147483647, 2147483647, -1,         0,          0,          2147483647, -1,         -1,         0,          -1,         2147483647, 0,          0,  0,          0,          0,          2147483647, 0,          0,          -1,         0,          0,          -1,         0,          -1,         0,          0,          -1}};

    wallsAndGates(k);
    return 0;
}