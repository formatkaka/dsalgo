//
// Created by Siddhant on 2019-09-20.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int countCharacters(vector<string>& words, string chars) {

    int charCount = 0;

    for (int i = 0; i < words.size(); ++i) {
        string word = words[i];
        string chars_copy = chars;
        bool invalid = false;
        for (int j = 0; j < word.size(); ++j) {
            char ch = word[j];
            if(chars_copy.find(ch) == string::npos){
                invalid = true;
                break;
            }
            chars_copy.erase(chars_copy.find(ch), 1);
        }

        if(!invalid){
            charCount += words[i].size();
        }
    }

    return charCount;

}

int main(){

    string chars = "cat";
    vector<string> words = {"catc","bt","hat","tree"};
    cout << "Ans : " << countCharacters(words, chars);
    return 0;
}