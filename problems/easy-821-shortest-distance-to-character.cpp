//
// Created by Siddhant on 2019-10-31.
//

#include "iostream"
#include "vector"
#include "string"
#include "algorithm"

using namespace std;

int getFirstE(string S, char C){

    for (int i = 0; i < S.length(); ++i) {
        if(S[i] == C){
            return i;
        }
    }

    return -1;

}


int getLastE(string S, char C){

    for (int i = S.length()-1; i >= 0; --i) {
        if(S[i] == C){
            return i;
        }
    }

    return -1;

}


int getNextE(string S, char C, int firstE){
    for (int i = firstE+1; i < S.length(); ++i) {

        if(S[i]==C){
            return i;
        }
    }

    return -1;
}

vector<int> shortestToChar(string S, char C) {

    vector<int> solution(S.length(), -1);
    int firstE = getFirstE(S, C);
    int lastE = getLastE(S, C);

    for (int i = 0; i < firstE; ++i) {
        solution[i] = firstE-i;
    }

    solution[firstE] = 0;

    for (int j = S.length()-1; j > lastE ; --j) {
        solution[j] = j-lastE;
    }

    solution[lastE] = 0;

    while(firstE != lastE){

        int nextE = getNextE(S, C, firstE);
        int midPoint = (firstE + nextE)/2;


        for (int i = firstE + 1; i <= midPoint; ++i) {
            solution[i] = i-firstE;
        }

        for (int j = midPoint+1; j < nextE; ++j) {
            solution[j] = nextE-j;
        }

        solution[nextE] = 0;

        firstE = nextE;
    }


    return solution;

}

int main(){

//    vector<int> sol = shortestToChar("loveleetcode", 'e');

    cout << max({1, 2, 4});

//    for (auto s = sol.begin(); s != sol.end(); ++s) {
//        cout << *s << ',';
//    }

    return 0;
}