//
// Created by Siddhant on 2019-11-23.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;



bool validPos(vector<vector<int>>& positions, vector<int> newpos){

    for (int i = 0; i < positions.size(); ++i) {

        int x1 = positions[i][0];
        int y1 = positions[i][1];

        int xn = newpos[0];
        int yn = newpos[1];


        if(xn == x1){
            return false;
        }

        if(yn == y1){
            return false;
        }

        // perpendicular
        if(abs(xn-x1) == abs(yn-y1)){
            return false;
        }


    }

    return true;

}

vector<string> convertCoordsToVC(vector<vector<int>>& pos){
    string row(pos.size(), '.');
    vector<string> s(pos.size(), row);

    for (int i = 0; i < pos.size(); ++i) {
        s[i][pos[i][1]] = 'Q';
    }

    return s;

}

void backtrack(vector<vector<string>>& res, vector<vector<int>> positions, int k, int n) {

    if(k == n){
        res.push_back(convertCoordsToVC(positions));
        return;
    }

    for (int i = 0; i < n; ++i) {

        vector<int> newpos = {k, i};

        if(validPos(positions, newpos)){

            positions.push_back(newpos);

            backtrack(res, positions, k+1, n);

            positions.pop_back();

        }

    }

}

vector<vector<string>> solveNQueens(int n) {

    vector<vector<string>> res;
    vector<vector<int>> positions = {};
    int start = 0;

    backtrack(res, positions, start, n);

    return res;

}

int main() {

    solveNQueens(8);
    return 0;
}