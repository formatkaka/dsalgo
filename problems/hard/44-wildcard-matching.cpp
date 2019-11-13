//
// Created by Siddhant on 2019-11-13.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"

using namespace std;

unordered_map<char, vector<int>> m;
vector<pair<char, int>> v;
bool done = 0;

void matchRec(string s, string p, int minBeginIndex, int pairToCheck) {

    if (minBeginIndex >= s.length() - 1) {
        done = true;
        return;
    }

    vector<int> zfirst = m[v[pairToCheck].first];
    vector<int> zsecond = m[v[pairToCheck + 1].first];

    int psIndex = v[pairToCheck].second;
    int peIndex = v[pairToCheck + 1].second;

    for (int i = 0; i < zfirst.size(); ++i) {

        for (int j = 0; j < zsecond.size(); ++j) {

            if (zfirst[i] >= minBeginIndex && zsecond[j] > zfirst[i]) {

                int slen = zsecond[j] - zfirst[i] - 1;
                int stars = 0, ques = 0;

                for (int k = psIndex + 1; k < peIndex; ++k) {
                    if (p[k] == '*') {
                        stars++;
                    } else {
                        ques++;
                    }
                }

                if ((stars >= 1 && ques <= slen) || (stars == 0 && ques == slen)) {
                    // true
                    matchRec(s, p, zsecond[j], pairToCheck + 1);
                } else {
                    //false
                }

            }

        }

    }

}

bool isMatch(string s, string p) {
    for (int i = 0; i < p.length(); ++i) {

        if (isalpha(p[i])) {
            m[p[i]] = {};
            v.push_back({p[i], i});
        }

    }

    for (int j = 0; j < s.length(); ++j) {

        if (m.find(s[j]) != m.end()) {
            m[s[j]].push_back(j);
        }

    }

    for (auto mapIt = m.begin(); mapIt != m.end(); ++mapIt) {

        if (mapIt->second.size() == 0) {
            return false;
        }

    }

    if(m.empty()){

        int stars = 0, ques = 0;

        for (int i = 0; i < p.length(); ++i) {

            if(p[i] == '*'){
                stars++;
            }else{
                ques++;
            }

        }

        if((stars >= 1 && ques <= s.length()) || (stars == 0 && ques == s.length())){
            done = true;
        }else{
            done = false;
        }

        return done;

    }

    int startCharIndexP = m[v[0].first][0];
    int endCharIndexP = m[v[v.size() - 1].first][m[v[v.size() - 1].first].size() - 1];

    int slen = startCharIndexP;
    int elen = s.length() - endCharIndexP - 1;

    int stars = 0, ques = 0;
    bool endStartOK;

    if (v[0].second > 0) {


        for (int k = 0; k < v[0].second; ++k) {

            if (p[k] == '*') {
                stars++;
            } else {
                ques++;
            }

        }

        if ((stars >= 1 && ques <= slen) || (stars == 0 && ques == slen)) {
            // true
            endStartOK = true;
        } else {
            //false
            endStartOK = false;
        }

    } else {
        endStartOK = true;
    }

    if (endStartOK && v[v.size() - 1].second < s.length() - 1) {
        stars = 0, ques = 0;
        for (int k = 0; k < v[v.size() - 1].second; ++k) {

            if (p[k] == '*') {
                stars++;
            } else {
                ques++;
            }

        }

        if ((stars >= 1 && ques <= elen) || (stars == 0 && ques == elen)) {
            // true
            endStartOK = true;
        } else {
            //false
            endStartOK = false;
        }

    }

    if(!endStartOK){
        done = false;
        return false;
    }

    matchRec(s, p, 0, 0);

}

int main() {

    string s = "adeceb";
    string p = "*eb";
    isMatch(s, p);
    cout << "done : " << done;
    return 0;
}