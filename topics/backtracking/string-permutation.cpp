//
// Created by Siddhant on 2019-09-25.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void print_vec(vector<string> word){
    for (auto character = word.begin(); character != word.end(); ++character) {
        cout << (*character);
    }
    cout << endl;
}

void stringPermutations(vector<string> letters,vector<string> result,vector<bool> used, int depth){

    if(depth == letters.size()){
        print_vec(result);
    }

    for (int i = 0; i < letters.size(); ++i) {

        if(used[i]){
            continue;
        }

        result.push_back(letters[i]);
        used[i] = true;
        depth = depth + 1;

        stringPermutations(letters, result, used, depth);

        used[i] = false;
        depth = depth - 1;
        result.pop_back();
    }

}

int main(){

    vector<string> letters = {"A", "B", "C"};
    vector<bool> used = {0, 0, 0};
    vector<string> result;
    stringPermutations(letters, result, used, 0);
    return 0;
}