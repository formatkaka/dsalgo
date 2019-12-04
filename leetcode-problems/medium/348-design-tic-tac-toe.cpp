//
// Created by Siddhant on 2019-12-03.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;

class TicTacToe {
public:
    unordered_map<int, vector<int>> rows;
    unordered_map<int, vector<int>> cols;
    unordered_map<int, vector<int>> diag;

    unordered_set<string> diag1;
    unordered_set<string> diag2;

    int magicnumber;

    /** Initialize your data structure here. */
    TicTacToe(int n) {

        vector<int> count = {0, 0, 0};

        for (int i = 0; i < n; i++) {
            diag1.insert(gethash(i, i));

            diag2.insert(gethash(n - 1 - i, i));

            rows[i] = count;
            cols[i] = count;
        }

        diag[1] = count; //
        diag[2] = count; // /

        magicnumber = n;

    }

    string gethash(int i, int j) {
        return to_string(i) + "#" + to_string(j);
    }

    bool iswinningmove(int row, int col, int player) {

        if (rows[row][player] == magicnumber) {
            return true;
        }

        if (cols[col][player] == magicnumber) {
            return true;
        }

        if (diag[1][player] == magicnumber) {
            return true;
        }

        if (diag[2][player] == magicnumber) {
            return true;
        }

        return false;

    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {

        rows[row][player]++;
        cols[col][player]++;

        if (diag1.find(gethash(row, col)) != diag1.end()) {
            diag[1][player]++;
        }

        if (diag2.find(gethash(row, col)) != diag2.end()) {
            diag[2][player]++;
        }

        bool winningmove = iswinningmove(row, col, player);

        if (winningmove) {
            return player;
        }

        return 0;

    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */

int main() {

    TicTacToe t(3);
    return 0;
}