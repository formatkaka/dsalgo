//
// Created by Siddhant on 2019-10-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int getMaxPerimeter(vector<vector<int>>& grid){
    int perimeter = 0;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            if(grid[i][j] == 1){
                perimeter += 4;
            }
        }
    }
    
    return perimeter;
}

int getOverlapEdges(vector<vector<int>>& grid){
    int overlaps = 0;
    
    
    // horizontal overlaps
    for (int i = 0; i < grid.size() - 1; ++i) {

        for (int j = 0; j < grid[i].size(); ++j) {

            if(grid[i][j] == 1 && grid[i][j] == grid[i+1][j]){
                overlaps++;
            }
        }
    }
    
    // vertical overlaps
    for (int i = 0; i < grid[0].size() - 1; ++i) {

        for (int j = 0; j < grid.size(); ++j) {

            if(grid[j][i] == 1 && grid[j][i] == grid[j][i+1]){
                overlaps++;
            }

        }

    }
//    cout << "Overlaps : " << overlaps << endl;
    return overlaps;
}

int islandPerimeter(vector<vector<int>>& grid) {

    int maxPerimeter = getMaxPerimeter(grid);
    int overlaps = getOverlapEdges(grid);

    return maxPerimeter - 2*overlaps;
}

int main(){

    vector<vector<int>> grid = {{0,1,0,0},
                                {1,0,1,0},
                                {0,1,0,0},
                                {1,1,0,0}};
    cout << "Perimeter is : " << islandPerimeter(grid);
    return 0;
}