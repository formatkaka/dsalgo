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

    bool union_sets(T d1, T d2) {

        // return true if sets union done
        // return false if they are already in the same union

        int root1 = find(d1);
        int root2 = find(d2);

        if (root1 == root2) {
            return false;
        }

        if (abs(data[root1]) > abs(data[root2])) {

            data[root1] = data[root1] + data[root2];
            data[root2] = root1;

        } else {

            data[root2] = data[root1] + data[root2];
            data[root1] = root2;

        }

        return true;

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

bool validTree(int n, vector<vector<int>> &edges) {

    UnionFind<int> uf(n);

    for (int i = 0; i < edges.size(); ++i) {

        bool iscycle = !uf.union_sets(edges[i][0], edges[i][1]);

        if(iscycle)
            return false;

    }

    bool root_is_same = uf.get_uniquesets() == 1;

    return root_is_same;

}

int main() {

    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}, {1,4}};
    cout << "tree is valid : " << validTree(6, edges);
    return 0;
}