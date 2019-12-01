//
// Created by Siddhant on 2019-11-30.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

template<class T>
class UnionFind {
    vector<T> data;

public:
    UnionFind(int size) {
        vector<T> vec(size, -1);
        data = vec;
    }

    void union_sets(T d1, T d2) {

        int root1 = find(d1);
        int root2 = find(d2);

        if (root1 == root2) {
            return;
        }

        if (abs(data[root1]) > abs(data[root2])) {

            data[root1] = data[root1] + data[root2];
            data[root2] = root1;

        } else {

            data[root2] = data[root1] + data[root2];
            data[root1] = root2;

        }

    }

    T find(T d) {

        while (data[d] >= 0) {
            d = data[d];
        }
        return d;
    }

    int get_uniquesets() {

        int unique_sets = 0;

        for (int i = 0; i < data.size(); ++i) {

            if (data[i] < 0) {
                unique_sets++;
            }

        }

        return unique_sets;

    }

};

int countComponents(int n, vector<vector<int>> &edges) {

    if (n == 1) {
        return 1;
    }

    UnionFind<int> uf(n);

    for (int e = 0; e < edges.size(); e++) {

        uf.union_sets(edges[e][0], edges[e][1]);

    }

    return uf.get_uniquesets();

}

int main() {

    int n = 3;
    vector<vector<int>> v = {{1, 0},
                             {2, 1}};
    countComponents(n, v);
    return 0;
}