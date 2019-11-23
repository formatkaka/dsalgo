//
// Created by Siddhant on 2019-09-26.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

vector<vector<int>> solution;

void print_vec(vector<int> word){
    for (auto character = word.begin(); character != word.end(); ++character) {
        cout << (*character);
    }
    cout << endl;
}

bool vectorAlreadyPresent(vector<int> word){

//    cout << "solution.size() : " << solution.size() << endl;

    if(solution.empty()){
        solution.push_back(word);
    }
    bool validWord = false;
    for (int i = 0; i < solution.size(); ++i) {
        bool isSolPermutationOfWord = false;
        vector<int> sol = solution[i];

        if(sol.size() != word.size()){
            continue;
        }

        for (int j = 0; j < word.size(); ++j) {
            if(find(sol.begin(), sol.end(), word[j]) == sol.end()){
                isSolPermutationOfWord = false;
                break;
            }else{
                isSolPermutationOfWord = true;
            }
        }

        if(isSolPermutationOfWord){
            validWord = false;
            break;
        }else{
            validWord = true;
        }
    }

    if(validWord){
        solution.push_back(word);
    }
}

void stringPermutations(vector<int> letters,vector<int> result,vector<bool> used, int depth){

    if(depth == letters.size()){
        return;
    }

    for (int i = 0; i < letters.size(); ++i) {

        if(used[i]){
            continue;
        }

        result.push_back(letters[i]);
        used[i] = true;
        depth = depth + 1;

        vectorAlreadyPresent(result);
        stringPermutations(letters, result, used, depth);

        used[i] = false;
        depth = depth - 1;
        result.pop_back();
    }
}

int main(){

    vector<int> letters = {1, 2, 3};
    vector<bool> used(letters.size());
    vector<int> result;

    stringPermutations(letters, result, used, 0);
    cout << "ouput size : " << solution.size() << endl;
    for (auto sol = solution.begin(); sol != solution.end(); ++sol) {
        print_vec(*sol);
    }
    return 0;
}