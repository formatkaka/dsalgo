//
// Created by Siddhant on 2019-12-02.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int findClosingBracketIndex(string s, int start) {

    int op = 1;
    int i = start;
    int cl = 0;

    while (op != cl) {

        i++;

        if (s[i] == '[')
            op++;

        if (s[i] == ']')
            cl++;
    }

    return i;

}

string dfs(string &s, int start, int end) {

    string res = "";
    int i = start;

    while (i <= end) {

        if (isdigit(s[i])) {
            cout << "isdigit : " << i << endl;
            string freq_s;

            // detect frequency, may be multiple digits
            while (isdigit(s[i])) {
                freq_s += s[i];
                i++;
            }

            i--;
            int closing = findClosingBracketIndex(s, i + 1);
            int freq = stoi(freq_s);

            // if(closing-(i+1) > 1){
            string brac = dfs(s, i + 2, closing - 1);
            cout << "brac : " << brac << endl;
            while (freq > 0) {
                res += brac;
                freq--;
            }

            // }

            i = closing;

        } else {

            res += s[i];

        }

        i++;

    }

    return res;

}

string decodeString(string s) {

    if (s.empty()) {
        return "";
    }

    return dfs(s, 0, s.length());
}

int main() {

    cout << decodeString("3[a]2[bc]");
    return 0;
}