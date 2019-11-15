//
// Created by Siddhant on 2019-11-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool combinationfound = false;

bool dfs(vector<vector<char>> &board, string word, int index, int i, int j){

    if(combinationfound){
        return true;
    }

    if(index == word.length()){
        cout << "combination found" << endl;
        combinationfound = true;
    }

    // up
    if(i>0 && board[i-1][j] == word[index] && board[i-1][j] != '*'){
        char c = board[i-1][j];
        board[i-1][j] = '*';
        dfs(board, word, index+1, i-1, j);
        board[i-1][j] = c;
    }

    // down
    if(i < board.size()-1 && board[i+1][j] == word[index] && board[i+1][j] != '*'){
        char c = board[i+1][j];
        board[i+1][j] = '*';
        dfs(board, word, index+1, i+1, j);
        board[i+1][j] = c;
    }

    // left
    if(j > 0 && board[i][j-1] == word[index] && board[i][j-1] != '*'){
        char c = board[i][j-1];
        board[i][j-1] = '*';
        dfs(board, word, index+1, i, j-1);
        board[i][j-1] = c;
    }

    // right
    if(j < board[i].size()-1 && board[i][j+1] == word[index] && board[i][j+1] != '*'){
        char c = board[i][j+1];
        board[i][j+1] = '*';
        dfs(board, word, index+1, i, j+1);
        board[i][j+1] = c;
    }


}

bool exist(vector<vector<char>> &board, string word) {

    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {

            if(board[i][j] == word[0]){
                dfs(board, word,1 , i, j);
            }

        }
    }
    cout << "found : " << combinationfound ;

}

int main() {

    vector<vector<char>> board =
            {
                    {'A', 'B', 'C', 'E'},
                    {'S', 'F', 'C', 'S'},
                    {'A', 'D', 'E', 'E'}
            };

    exist(board, "ABCB");

    return 0;
}