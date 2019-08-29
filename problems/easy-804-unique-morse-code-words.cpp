#include "iostream"
#include "vector"
#include "string"
#include "unordered_set"

using namespace std;

int main(){

    vector<string> words = {"gin", "zen", "gig", "msg"};
    string charToMorseMap[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    unordered_set<string> output;

    for (auto word = words.begin(); word != words.end(); ++word) {
        string morse = "";
        for (auto character = (*word).begin(); character != (*word).end(); ++character) {
            morse += charToMorseMap[*character - 97];
        }
        cout << "morse : " << morse << endl;
        output.insert(morse);
    }

    cout << "morse length : " << output.size();

    return 0;
}