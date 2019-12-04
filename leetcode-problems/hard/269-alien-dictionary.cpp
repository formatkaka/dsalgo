//
// Created by Siddhant on 2019-12-03.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "unordered_set"

using namespace std;

unordered_map<char, vector<char>> graph;

// checking for invalid
/*
 * Checking for invalid
 *
 * 1. word2.len < word1.len
 *    Until the point their len are same, if word1 == word, then return false
 *    because input is false based on lexico. ordering based on length
 *
 * 2. Graph has cycle
 *
 */

bool invalidInput = false;

void addVertex(char c){
    if(graph.find(c) != graph.end()) return;

    vector<char> x;
    graph[c] = x;
}

void buildGraph(vector<string> &words){

    for (int i = 0; i < words.size()-1; ++i) {

        string word1 = words[i];
        string word2 = words[i+1];

        int j = 0;

        while(j < word1.length() && j < word2.length() && word1[j] == word2[j]){
            addVertex(word1[j]);
            j++;
        }


        if(j > word1.length()-1 || j > word2.length()-1 ){
            // invalid
            if(word2.length() < word1.length()) {
                invalidInput = true;
                return;
            }

            // otherwise continue
            continue;
        }


        graph[word1[j]].push_back(word2[j]);
        j++;

        while(j < word1.length()){
            addVertex(word1[j]);
            j++;
        }


    }

    for (int k = 0; k < words[words.size() - 1].size(); ++k) {

        addVertex(words[words.size()-1][k]);

    }

}

void dfsvisit(string& sol, char vertex, unordered_set<char>& visited, unordered_set<char> recStack){

    if(invalidInput){
        return;
    }

    recStack.insert(vertex);

    for (int i = 0; i < graph[vertex].size(); ++i) {



        char node = graph[vertex][i];

        if(recStack.find(node) != recStack.end()){
            invalidInput = true;
            return;
        }

        if(visited.find(node) != visited.end()){
            continue;
        }

        visited.insert(node);
        dfsvisit(sol, node, visited, recStack);

    }

    recStack.erase(vertex);

    sol += vertex;

}

void dfs(string& sol){

    unordered_set<char> visited;
    unordered_set<char> recStack;

    for (auto g = graph.begin(); g != graph.end(); ++g) {

        if(visited.find(g->first) != visited.end()){
            continue;
        }

        visited.insert(g->first);
        dfsvisit(sol, g->first, visited, recStack);

    }

}



string alienOrder(vector<string> &words) {

    buildGraph(words);

    if(invalidInput){
        return "";
    }

    string sol = "";
    dfs(sol);

    if(invalidInput){
        return "";
    }

    reverse(sol.begin(), sol.end());
    return sol;
}

int main() {

    vector<string> words = {
            "z",
            "zabc"
    };

    cout << alienOrder(words);
    return 0;
}