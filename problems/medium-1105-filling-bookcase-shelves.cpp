//
// Created by Siddhant on 2019-11-03.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

unordered_map<int, int> map;

int minHeightShelves(vector<vector<int>>& books, int shelf_width) {

    if(books.empty()){
        return 0;
    }

    if(map.find(books.size()) != map.end()){
        cout << "common : " << books.size() << endl;
        return map[books.size()];
    }

    int minHeight = INT_MAX;
    int rowHeight = INT_MIN;
    int widthOccupied = 0;
    for (int i = 0; i < books.size(); ++i) {


        widthOccupied += books[i][0];
        rowHeight = max(rowHeight, books[i][1]);

        if(widthOccupied > shelf_width){
            continue;
        }

//        cout << "not more" << endl;

        vector<vector<int>> booksOnNextShelf(books.begin() + i + 1, books.end());
        minHeight = min(minHeight, rowHeight + minHeightShelves(booksOnNextShelf, shelf_width));
    }

    map.insert(make_pair(books.size(), minHeight));

    return minHeight;

}

int main(){

//    vector<vector<int>> vec = {{1,1},{2,3}, {2,3}};
    vector<vector<int>> vec = {{1,1},{2,3},{2,3},{1,1},{1,1},{1,1},{1,2}};
    cout << "min height : " << minHeightShelves(vec, 4);
    return 0;
}