//
// Created by Siddhant on 2019-10-15.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void checkVisit(vector<vector<int>>& rooms, int roomIndex, vector<bool>& roomVisitedFlag){

    if(roomVisitedFlag[roomIndex]){
        return;
    }

    roomVisitedFlag[roomIndex] = true;

    for (int i = 0; i < rooms[roomIndex].size(); ++i) {
        checkVisit(rooms, rooms[roomIndex][i], roomVisitedFlag);
    }

//    return;

}

bool canVisitAllRooms(vector<vector<int>>& rooms) {

    vector<bool> roomVisitedFlag(rooms.size(), false);
    checkVisit(rooms, 0, roomVisitedFlag);
    for (int i = 0; i < roomVisitedFlag.size(); ++i) {
//        cout << "room num " << i << " " << roomVisitedFlag[i] << endl;
        if(!roomVisitedFlag[i]){
            return false;
        }
    }
    return true;


}

int main(){

    vector<vector<int>> rooms = {{1,3},{3,0,1, 2},{2, 1},{0}};
    cout << "can visit all rooms : " << canVisitAllRooms(rooms);

    return 0;
}