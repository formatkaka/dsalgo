//
// Created by Siddhant on 2019-11-22.
//

#include "graph.h"

#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

string gethash(int n1, int n2) {
    return to_string(n1) + "#" + to_string(n2);
}

void printPath(int m, int n, int d) {

    Graph<string> g((m + 1) * (n + 1));
    unordered_set<string> done;

    string hashres1 = gethash(0, d);
    string hashres2 = gethash(d, 0);
    string beginhash = gethash(0, 0);
    done.insert(beginhash);

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    while (!q.empty()) {


        pair<int, int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();

        string hashcurr = gethash(i, j);
        done.insert(hashcurr);

        // Empty jug 1
        string hash1 = gethash(0, j);
        if (i > 0 && done.find(hash1) == done.end()) {

            g.addEdge(hashcurr, hash1);
            q.push(make_pair(0,j));
            done.insert(hash1);
        }

        // Empty jug 2
        string hash2 = gethash(i, 0);
        if (j > 0 && done.find(hash2) == done.end()) {

            g.addEdge(hashcurr, hash2);
            q.push(make_pair(i,0));
            done.insert(hash2);
        }

        // Fill jug 1
        string hash3 = gethash(m, j);
        if (done.find(hash3) == done.end()) {
            g.addEdge(hashcurr, hash3);
            q.push(make_pair(m,j));
            done.insert(hash3);
        }

        // Fill jug 2
        string hash4 = gethash(i, n);
        if (done.find(hash4) == done.end()) {
            g.addEdge(hashcurr, hash4);
            q.push(make_pair(i,n));
            done.insert(hash4);
        }


        // Fill jug 1 into jug2
        int maxPour1 = min(i, n - j);
        string hash5 = gethash(i - maxPour1, j + maxPour1);
        if (done.find(hash5) == done.end()) {
            g.addEdge(hashcurr, hash5);
            q.push(make_pair(i-maxPour1,j+maxPour1));
            done.insert(hash5);
        }

        // Fill jug 1 into jug2
        int maxPour2 = min(m - i, j);
        string hash6 = gethash(i + maxPour2, j - maxPour2);
        if (done.find(hash6) == done.end()) {
            g.addEdge(hashcurr, hash6);
            q.push(make_pair(i + maxPour2, j - maxPour2));
            done.insert(hash6);
        }

    }

    cout << "d1 : " << g.shortestDistance(beginhash, hashres1) + 1 << endl;
    cout << "d2 : " << g.shortestDistance(beginhash, hashres2) + 1 << endl;
}



int main() {

    printPath(4, 3, 8);
    return 0;
}

