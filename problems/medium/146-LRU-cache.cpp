//
// Created by Siddhant on 2019-11-09.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

class LRUCache {
private:
    unordered_map<int, vector<int>> map;

    void deleteLRU(){
        int minKey = -1, minAge = INT_MAX;

        for(auto it = map.begin(); it != map.end(); it++){
            if((it->second)[1] < minAge){
                minKey = it->first;
                minAge = (it->second)[1];
            }
        }

        map.erase(minKey);
    }

public:
    int maxAge;
    int cacheCapacity;
    LRUCache(int capacity) {
        maxAge = 0;
        cacheCapacity = capacity;
    }

    int get(int key) {
        if(map.find(key) != map.end()){
            maxAge++;
            map[key][1] = maxAge;
            return map[key][0];
        }

        return -1;
    }

    void put(int key, int value) {

        if(map.size() == cacheCapacity){
            deleteLRU();
        }

        // if(map.size() < cacheCapacity){
        maxAge++;
        vector<int> val = {value, maxAge};
        map.insert(make_pair(key, val));
        return;
        // }


    }
};

int main(){

    LRUCache l(2);
    l.put(1,1);
    l.put(2,2);
    cout << "get 1 : " << l.get(1) << endl;
    l.put(3,3);
    cout << "get 2 : " << l.get(2) << endl;
    return 0;
}