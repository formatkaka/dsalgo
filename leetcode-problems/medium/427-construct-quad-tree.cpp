//
// Created by Siddhant on 2019-11-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;


// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


Node *build(vector<vector<int>> &grid, vector<int> x, vector<int> y) {

    if (y[0] - x[0] == 1) {
        int gridside = grid.size();
        // Base condition
        cout << "val : " << x[0] << " , " << x[1] << " : " << endl;
        cout << "val : " << gridside - x[1] - 1 << " , " << x[0] << " : " << grid[gridside - x[1] - 1][x[0]] << endl;
        Node *n = new Node(grid[gridside - x[1] - 1][x[0]], true, NULL, NULL, NULL, NULL);
        return n;
    }

    vector<int> br1 = {(x[0] + y[0]) / 2, x[1]};
    vector<int> br2 = {y[0], (x[1] + y[1]) / 2};
    Node *bottomRight = build(grid, br1, br2);

    vector<int> bL2 = {(x[0] + y[0]) / 2, (x[1] + y[1]) / 2};
    Node *bottomLeft = build(grid, x, bL2);

    vector<int> tl1 = {x[0], (x[1] + y[1]) / 2};
    vector<int> tl2 = {(x[0] + y[0]) / 2, y[1]};
    Node *topLeft = build(grid, tl1, tl2);

    vector<int> tr1 = {(x[0] + y[0]) / 2, (x[1] + y[1]) / 2};
    Node *topRight = build(grid, tr1, y);


    bool allChildLeaf = bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->isLeaf && topRight->isLeaf;

    if ( bottomLeft->val == topLeft->val && topRight->val == bottomRight->val && bottomLeft->val == topRight->val &&
        allChildLeaf) {

        // if all children are same

        Node *n = new Node(bottomLeft->val, true, NULL, NULL, NULL, NULL);
        return n;
    }

    Node *n = new Node('*', false, topLeft, topRight, bottomLeft, bottomRight);
    return n;

}

Node *construct(vector<vector<int>> &grid) {

    vector<int> pt1 = {0, 0};
    vector<int> pt2 = {8, 8};

    return build(grid, pt1, pt2);

}


int main() {

    vector<vector<int>> g = {{1, 1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 0, 0, 0, 0},
                             {1, 1, 1, 1, 0, 0, 0, 0}};

//    vector<vector<int>> g = {{1, 1, 1, 1},
//                             {1, 1, 1, 1},
//                             {1, 1, 1, 1},
//                             {0, 1, 1, 1}};
    Node* n = construct(g);
//    cout << g.size();
    cout << 'hello';
    return 0;
}