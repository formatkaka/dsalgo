//
// Created by Siddhant on 2019-11-27.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"
#include "stack"

using namespace std;

class Graph {

public:

    unordered_map<string, vector<pair<string, double>>> g;

    void addedge(string &s, string &t, double w) {
        g[s].push_back(make_pair(t, w));
    }

    double calculateEq(string &s, string &t) {

        if(s == t && g.find(s) == g.end()){
            return -1;
        }

        double ans = 1;
        bool found = false;
        unordered_set<string> visited;

        stack<pair<string, double>> st;
        st.push(make_pair(s, 1));


        while (!found && !st.empty()) {

            pair<string, double> top = st.top();
            st.pop();

            if (visited.find(top.first) != visited.end()) {
                continue;
            }

            visited.insert(top.first);

            if (top.first == t) {
                ans = top.second;
                found = true;
            }

            for (int i = 0; i < g[top.first].size(); ++i) {


                string x = g[top.first][i].first;
                double v = g[top.first][i].second;

                if (visited.find(x) != visited.end()) {
                    continue;
                }

                double newval = top.second * v;
                st.push(make_pair(x, newval));

            }

        }


        if(!found){
            double defans = -1;
            return defans;
        }

        return ans;

    }

};

vector<double>
calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {

    Graph g;
    vector<double> soln;

    for (int i = 0; i < equations.size(); ++i) {

        double reverse = 1 / (values[i]);

        g.addedge(equations[i][0], equations[i][1], values[i]);
        g.addedge(equations[i][1], equations[i][0], reverse);

    }

    for (int j = 0; j < queries.size(); ++j) {

        soln.push_back(g.calculateEq(queries[j][0], queries[j][1]));

    }

    return soln;

}

int main() {

    vector<vector<string>> equations = {{"a", "b"},
                                              {"b", "c"},{"d","d"}};
    vector<double> values = {2.0, 3.0, 1.0};
    vector<vector<string>> queries = {{"a", "c"},
                                            {"b", "a"},{"k","k"}, {"b", "b"}, {"d","e"}};

    calcEquation(equations, values, queries);
    return 0;
}