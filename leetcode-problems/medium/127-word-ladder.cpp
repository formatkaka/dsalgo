//
// Created by Siddhant on 2019-11-27.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "queue"

using namespace std;

class Graph {

public:
    unordered_map<string, vector<string>> g;

    void addedge(string u, string v) {

        g[u].push_back(v);
        g[v].push_back(u);

    }

    int shortestPath(string u, string v) {

        if(u == v){
            return 1;
        }

        queue<string> q;
        unordered_set<string> visited;
        unordered_map<string, string> parent;
        q.push(u);
        visited.insert(u);
        int len = 1;

        while (!q.empty()) {

            int q_size = q.size();

            while (q_size > 0) {

                string node = q.front();
                q.pop();

                if(node == v){
                    return len;
                }

                for (int i = 0; i < g[node].size(); ++i) {

                    if(visited.find(g[node][i]) != visited.end()){
                        continue;
                    }

                    parent[g[node][i]] = node;
                    q.push(g[node][i]);
                    visited.insert(g[node][i]);

//                    if (g[node][i] == v) {
//
//                        string n = g[node][i];
//
//                        return len;
//                    }


                }

                q_size--;
            }

            len++;

        }
        return -1;
    }

};

int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    Graph g;

    for (int i = 0; i < wordList.size(); ++i) {

        for (int j = i; j < wordList.size(); ++j) {

            int diffcount = 0;

            for (int k = 0; k < wordList[i].size(); ++k) {

                if (wordList[i][k] != wordList[j][k]) {
                    diffcount++;
                }

                if (diffcount > 1) {
                    break;
                }

            }

            if (diffcount == 1 && wordList[i] != beginWord && wordList[j] != beginWord) {
                g.addedge(wordList[i], wordList[j]);
            }

        }

    }

    int ans = INT_MAX;
    bool diffFound = false;

    for (int l = 0; l < wordList.size(); ++l) {

        int diffcount = 0;

        if(wordList[l] == beginWord){
            continue;
        }

        for (int k = 0; k < wordList[l].size(); ++k) {

            if (wordList[l][k] != beginWord[k]) {
                diffcount++;
            }

            if (diffcount > 1) {
                break;
            }

        }

        if(diffcount == 1){
            diffFound = true;
            ans = min(ans, 1 + g.shortestPath(wordList[l], endWord));
        }

    }

    if(!diffFound){
        return 0;
    }

    cout << "Min dist is : " << ans;
    return ans;

}

int main() {

//    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<string> wordList = {"a", "b", "c"};
    ladderLength("a", "c", wordList);
    return 0;
}