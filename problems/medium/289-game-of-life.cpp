//
// Created by Siddhant on 2019-11-13.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int getUpdatedCell(vector<vector<int>> &board, int i, int j) {

    int countOnes = 0;

    cout << "i : " << i << " j : " << j << endl;

    for (int k = -1; k <= 1; ++k) {

        for (int l = -1; l <= 1; ++l) {

            if (k == 0 && l == 0) {

            } else {

                cout << " k : " << k << " l : " << l << endl;

                bool iok = i + k >= 0 && i + k < board.size();
                bool jok = j + l >= 0 && j + l < board[i].size();

                if (jok && iok && board[i + k][j + l] == 1) {
                    cout << "i+k : " << i + k << " j+l : " << j + l << endl;
                    countOnes++;
                }
            }

        }

    }
    cout << endl << endl;
    if (countOnes < 2 || countOnes > 3) {
        return 0;
    }

    if (countOnes == 3) {
        return 1;
    }

    if (countOnes == 2) {
        return board[i][j] == 1 ? 1 : 0;
    }

}

void gameOfLife(vector<vector<int>> &board) {
    vector<int> v;
    vector<int> t;

    for (int j = 0; j < board.size(); ++j) {

        for (int k = 0; k < board[j].size(); ++k) {

            v.push_back(getUpdatedCell(board, j, k));

        }


        if (j > 0) {
            board[j - 1] = t;
        }

        t = v;
        v = {};
    }

    board[board.size()-1] = t;

    for (auto brow = board.begin(); brow != board.end(); ++brow) {

        for (auto b = (*brow).begin(); b != (*brow).end(); ++b) {

            cout << *b << ',';

        }
        cout << endl;

    }
}

int main() {

    vector<vector<int>> board = {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
    };

    gameOfLife(board);

    return 0;
}

//[[1,1,1],[1,1,1],[1,1,1],[1,1,1]]