//
// Created by Siddhant on 2019-11-29.
//

#include "iostream"
#include "vector"
#include "string"
#include "list"

using namespace std;

bool compare(const vector<int>& p1, const vector<int>& p2){

    if(p1[0] != p2[0]){
        return p1[0] < p2[0];
    }

    return p1[1] > p2[1];

}

vector<vector<int>> reconstructQueue(vector<vector<int>> &people) {

    sort(people.begin(), people.end(), compare);

    list<vector<int>> reorder;
    vector<vector<int>> result;

    for (int i = people.size()-1; i >= 0; --i) {

        vector<int> person = people[i];

        int person_k = person[1];
        auto it = next(reorder.begin(), person_k);

        reorder.insert(it, person);

    }

    for (auto listIterator = reorder.begin(); listIterator != reorder.end(); ++listIterator) {
        result.push_back(*listIterator);
    }

    return result;

}

int main() {

    vector<vector<int>> people = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
    reconstructQueue(people);
    return 0;
}