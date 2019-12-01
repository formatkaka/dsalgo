//
// Created by Siddhant on 2019-11-29.
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

        while(data[d] > 0){
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

int findCircleNum(vector<vector<int>> &M) {

    UnionFind<int> uf(M.size());

    for (int i = 0; i < M.size(); ++i) {

        for (int j = i + 1; j < M[i].size(); ++j) {

            if (M[i][j] == 1) {

                uf.union_sets(i, j);

            }

        }

    }

    return uf.get_uniquesets();

}

int main() {

    vector<vector<int>> M = {{1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1},
                             {1, 1, 1, 1, 1}};

    cout << "friend groups are : " << findCircleNum(M);
    return 0;
}