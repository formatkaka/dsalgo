//
// Created by Siddhant on 2019-11-24.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"

using namespace std;

class Graph{

public:
    unordered_map<string, vector<string>> g;
    Graph(){};

    void addEdge(string start, string des){
        g[start].push_back(des);
    }

};

bool done;

void find(Graph g, vector<string>& res, string code, vector<string>& finalres, int t){

    if(done){
        return;
    }

    if(res.size() == t){
        res.push_back(code) ;
        finalres = res;
        done = true;
        return;
    }

    sort(g.g[code].begin(), g.g[code].end());

    for (int i = 0; i < g.g[code].size(); ++i) {
        string c = g.g[code][i];
        g.g[code].erase(g.g[code].begin()+i, g.g[code].begin()+i+1);

        res.push_back(code);
        find(g, res, c, finalres, t);
        res.pop_back();

        g.g[code].insert(g.g[code].begin()+i, c);

    }

}

vector<string> findItinerary(vector<vector<string>> &tickets) {

    Graph g;

    for (int i = 0; i < tickets.size(); ++i) {
        g.addEdge(tickets[i][0], tickets[i][1]);
    }
    vector<string> res;
    vector<string> finalres;
    find(g, res, "JFK", finalres, tickets.size());
    return finalres;

}

int main() {

//    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
//    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    findItinerary(tickets);
    return 0;
}