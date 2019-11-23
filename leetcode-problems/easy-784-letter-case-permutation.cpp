//
// Created by Siddhant on 2019-10-14.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int getFirstAlphabetPos(string S){

    for (int i = 0; i < S.size(); ++i) {

        if(isalpha(S[i])){
            return i;
        }
    }

    return S.length();

}

vector<string> res;

void recursiveLetterPerm(string prefix, string permute){


    int firstAlphabetPos = getFirstAlphabetPos(permute);

    if(permute.length() == 0 || firstAlphabetPos > permute.length() - 1 ){
        return;
    }

    string substr = permute.substr(0, firstAlphabetPos);
    string prefix_lowercase = prefix + substr + (char) tolower(permute[firstAlphabetPos]);
    string prefix_uppercase = prefix + substr + (char) toupper(permute[firstAlphabetPos]);
    string permuteleftover = permute.substr(firstAlphabetPos+1);

    string s1 = prefix_lowercase + permuteleftover;
    string s2 = prefix_uppercase + permuteleftover;
    res.push_back(s1);
    res.push_back(s2);

    recursiveLetterPerm(prefix_lowercase, permuteleftover);
    recursiveLetterPerm(prefix_uppercase, permuteleftover);

    return;
}

vector<string> letterCasePermutation(string S) {

    recursiveLetterPerm("", S);

    for (int i = 0; i < res.size()-1; ++i) {
        auto z = res[i];
        cout << res[i] << endl;
    }

    cout << "length : " << res.size() << endl;

}

int main(){

    letterCasePermutation("abc");
    return 0;
}