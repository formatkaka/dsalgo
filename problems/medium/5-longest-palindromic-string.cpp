//
// Created by Siddhant on 2019-11-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

string longestPalindrome(string s) {
    int st = 0, end = 0;

    for (int i = 0; i < s.length(); i++) {

        int lo = i - 1;
        int hi = i + 1;
        int localst = 0, localend = 0;

        if (hi < s.length() && s[i] == s[hi] && (lo < 0 || (lo >= 0 && s[lo] != s[hi]))) {
            hi++;
            localst = i;
            localend = i + 1;
        }

        while (lo >= 0 && hi <= s.length() - 1) {

            if (s[lo] == s[hi]) {
                localst = lo;
                localend = hi;
            } else {
                break;
            }
            lo--;
            hi++;
        }

        if ((localend - localst) > (end - st)) {
            end = localend;
            st = localst;
        }

    }

    return s.substr(st, (end - st + 1));

}

int main() {

    cout << "longest : " << longestPalindrome("akbbaaaa");
    return 0;
}