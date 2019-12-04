//
// Created by Siddhant on 2019-12-01.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

const char ZERO = '0';
const char ONE = '1';

int maxRowArea(vector<int> &row) {

    int len = 0;
    int min_val = INT_MAX;
    int max_row_area = 0;
    int only_row_area = 0;

    for (int i = 0; i < row.size(); ++i) {

        if (row[i] > 1) {
            len++;
            min_val = min(min_val, row[i]);
            max_row_area = max({max_row_area, len * min_val});

            if (i == row.size() - 1) {
                max_row_area = max({max_row_area, len * min_val});
            }

        }

        if (row[i] <= 1) {

            len = 0;
            min_val = INT_MAX;
        }

        if (row[i] > 0) {
            only_row_area++;
            max_row_area = max(max_row_area, only_row_area);

            if (i == row.size() - 1) {
                max_row_area = max({max_row_area, only_row_area});
            }
        }

        if (row[i] == 0) {

            only_row_area = 0;
        }

    }

    return max_row_area;

}

int maximalRectangle(vector<vector<char>> &matrix) {

    if (matrix.empty())
        return 0;

    if (matrix[0].empty()) {
        return 0;
    }


    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    int maxArea = 0;

    for (int k = 0; k < matrix[0].size(); ++k) {

        dp[0][k] = matrix[0][k] == ONE ? 1 : 0;

    }

    maxArea = max(maxArea, maxRowArea(dp[0]));

    for (int i = 1; i < matrix.size(); ++i) {

        for (int j = 0; j < matrix[i].size(); ++j) {

            if (matrix[i][j] == ZERO) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = 1 + dp[i - 1][j];
            }

        }

        maxArea = max(maxArea, maxRowArea(dp[i]));

    }

    return maxArea;

}

int main() {

    vector<vector<char>> v = {
            {'1', '0', '1', '1', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '1', '1', '0'}
    };

    vector<vector<char>> v1 = {{'1', '1', '1'}};

    vector<vector<char>> v3 = {{'0', '0', '1', '0'},
                               {'1', '1', '1', '1'},
                               {'1', '1', '1', '1'},
                               {'1', '1', '1', '0'},
                               {'1', '1', '0', '0'},
                               {'1', '1', '1', '1'},
                               {'1', '1', '1', '0'}};

    cout << pow(0.1, 1000);
//    cout << maximalRectangle(v3);
    return 0;
}