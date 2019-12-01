//
// Created by Siddhant on 2019-11-30.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"

using namespace std;

const char O = 'O';
const char X = 'X';
const char P = '-';

template<class T>
class UnionFind {
    vector<T> data;

public:
    UnionFind(int size) {
        vector<T> vec(size, -1);
        data = vec;
    }

    bool union_sets(T d1, T d2) {

        // return true if sets union done
        // return false if they are already in the same union

        int root1 = find(d1);
        int root2 = find(d2);

        if (root1 == root2) {
            return false;
        }

        if (abs(data[root1]) > abs(data[root2])) {

            data[root1] = data[root1] + data[root2];
            data[root2] = root1;

        } else {

            data[root2] = data[root1] + data[root2];
            data[root1] = root2;

        }

        return true;

    }

    T find(T d) {

        while (data[d] >= 0) {
            d = data[d];
        }
        return d;
    }

    int get_uniquesets() {

        int unique_sets = 0;

        for (int i = 0; i < data.size(); ++i) {

            if (data[i] < 0) {
                unique_sets++;
            }

        }

        return unique_sets;

    }

};

void exploreGraphAndMark(vector<vector<char>> &board, int i, int j) {

    queue<pair<int, int>> q;
    q.push({i, j});
    board[i][j] = P;

    while (!q.empty()) {

        pair<int, int> p = q.front(); q.pop();

        i = p.first;
        j = p.second;

        if (i > 0 && board[i - 1][j] == O) {
            board[i - 1][j] = P;
            q.push({i - 1, j});
        }

        if (i < board.size() - 1 && board[i + 1][j] == O) {
            board[i + 1][j] = P;
            q.push({i + 1, j});
        }

        if (j > 0 && board[i][j - 1] == O) {
            board[i][j - 1] = P;
            q.push({i, j - 1});
        }

        if (j < board[i].size() - 1 && board[i][j + 1] == O) {
            board[i][j+1] = P;
            q.push({i, j+1});
        }

    }

}

void solve(vector<vector<char>> &board) {

    for (int i = 0; i < board.size(); ++i) {

        int j_start = 0;
        int j_end = board[0].size()-1;

        if(board[i][j_start] == O){
            exploreGraphAndMark(board, i, 0);
        }

        if(board[i][j_end] == O){
            exploreGraphAndMark(board, i, j_end);
        }

    }

    for (int j = 0; j < board[0].size(); ++j) {

        int i_start = 0;
        int i_end = board.size()-1;

        if(board[i_start][j] == O){
            exploreGraphAndMark(board, i_start, j);
        }

        if(board[i_end][j] == O){
            exploreGraphAndMark(board, i_end, j);
        }

    }

    for (int i = 0; i < board.size(); ++i) {

        for (int j = 0; j < board[i].size(); ++j) {

            if(board[i][j] == O){
                board[i][j] = X;
            }

            if(board[i][j] == P){
                board[i][j] = O;
            }

        }

    }

    cout << "done";

}

int main() {

    vector<vector<char>> v = {{'X', 'O', 'X'}};
    solve(v);
    return 0;
}