//
// Created by Siddhant on 2019-10-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<int> getRookPosition(vector<vector<char>> &board) {

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {

            if (board[i][j] == 'R') {
                return {i, j};
            }

        }
    }

}

int numRookCaptures(vector<vector<char>> &board) {

    vector<int> rookPos = getRookPosition(board);
    int totalKills = 0;

    // left
    for (int i = rookPos[1] - 1; i >= 0; --i) {

        if (board[rookPos[0]][i] == 'B') {
            break;
        }

        if (board[rookPos[0]][i] == 'p') {
            totalKills += 1;
            break;
        }

    }

    // right
    for (int i = rookPos[1] + 1; i < board[rookPos[0]].size(); ++i) {

        if (board[rookPos[0]][i] == 'B') {
            break;
        }

        if (board[rookPos[0]][i] == 'p') {
            totalKills += 1;
            break;
        }

    }

    // top
    for (int i = rookPos[0] + 1; i < board.size(); ++i) {

        if (board[i][rookPos[1]] == 'B') {
            break;
        }

        if (board[i][rookPos[1]] == 'p') {
            totalKills += 1;
            break;
        }

    }

    // left
    for (int i = rookPos[0] - 1; i >= 0; --i) {

        if (board[i][rookPos[1]] == 'B') {
            break;
        }

        if (board[i][rookPos[1]] == 'p') {
            totalKills += 1;
            break;
        }

    }

    return totalKills;

}

int main() {

    vector<vector<char>> board = {{'.', '.', '.', '.', '.', '.', '.', '.'},
                                  {'.', 'p', 'p', 'p', 'p', 'p', '.', '.'},
                                  {'.', 'p', 'p', 'B', 'p', 'p', '.', '.'},
                                  {'.', 'p', 'B', 'R', 'B', 'p', '.', '.'},
                                  {'.', 'p', 'p', '.', 'p', 'p', '.', '.'},
                                  {'.', 'p', 'p', '.', 'p', 'p', '.', '.'},
                                  {'.', '.', '.', 'p', '.', '.', '.', '.'},
                                  {'.', '.', '.', 'p', '.', '.', '.', '.'}};

    cout << "max kills : " << numRookCaptures(board) << endl;

    return 0;
}