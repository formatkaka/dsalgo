//
// Created by Siddhant on 2019-11-28.
//

#include "iostream"
#include "vector"
#include "string"
#include "queue"

using namespace std;

int findConnectedServers(vector<vector<int>> &grid, int row, int col){

    queue<pair<int, int>> q;
    int connected = 0;

    q.push({row, col});
    grid[row][col] = 0;

    while(!q.empty()){

        int q_size = q.size();

        while(q_size > 0){

            pair<int, int> coord = q.front();
            q.pop();
            int X = coord.first;
            int Y = coord.second;

            for (int x = 0; x < grid.size(); ++x) {

                if(x == X)
                    continue;

                if(grid[x][Y] == 1){
                    q.push(make_pair(x,Y));
                    grid[x][Y] = 0;
                    connected++;
                }

            }

            for (int y = 0; y < grid[0].size(); ++y) {

                if(y == Y)
                    continue;

                if(grid[X][y] == 1){
                    q.push(make_pair(y,Y));
                    grid[X][y] = 0;
                    connected++;
                }

            }

//            if(y > 0 && grid[x][y-1] == 1){
//                q.push(make_pair(x, y-1));
//                grid[x][y-1] = 0;
//                connected++;
//            }
//
//            if(y < grid[0].size() - 1 && grid[x][y+1] == 1){
//                q.push(make_pair(x, y+1));
//                grid[x][y+1] = 0;
//                connected++;
//            }
//
//            if(x > 0 && grid[x-1][y] == 1){
//                q.push(make_pair(x-1, y));
//                grid[x-1][y] = 0;
//                connected++;
//            }
//
//            if(x < grid.size() - 1 && grid[x+1][y] == 1){
//                q.push(make_pair(x+1, y));
//                grid[x+1][y] = 0;
//                connected++;
//            }


            q_size--;
        }

    }

    return connected;

}

int countServers(vector<vector<int>> &grid) {

    int totalConnectedServers = 0;

    for (int row = 0; row < grid.size(); ++row) {

        for (int col = 0; col < grid[row].size(); ++col) {


            if(grid[row][col] == 0){
                continue;
            }

            int connectedServers = findConnectedServers(grid, row, col);

            if(connectedServers > 0){
                totalConnectedServers = totalConnectedServers + connectedServers + 1;
            }


        }

    }

    return totalConnectedServers;
}

int main() {

    vector<vector<int>> grid = {{1,0,0,0},{0,0,1,0},{0,0,1,0},{0,0,0,1}};
    cout << "total connected servers are : " << countServers(grid);
    return 0;
}