//
// Created by Siddhant on 2019-11-17.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

long find(unordered_map<int, int> &map, int num) {
    int n = pow(10, 9) + 7;
    if (num == 0) {
        return 1;
    }

    if (num == 2) {
        return 1;
    }

    if (map.find(num) != map.end()) {
        return map[num];
    }

    long handshakes = 0;

    for (int i = 0; i < num; i += 2) {
        handshakes = (handshakes + find(map, i) * find(map, num - i - 2)) % n;
    }

    handshakes = handshakes % n;
    map[num] = handshakes;
    return handshakes;

}

int numberOfWays(int num_people) {
    unordered_map<int, int> map;
    return (int) find(map, num_people);
}

int main() {

    cout << numberOfWays(20);
    return 0;
}