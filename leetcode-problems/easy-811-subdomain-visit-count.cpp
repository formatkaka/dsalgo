//
// Created by Siddhant on 2019-09-24.
//

#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"

using namespace std;

vector<string> subdomainVisits(vector<string>& cpdomains) {
    unordered_map<string, int> cpDomainMap;

    for (int i = 0; i < cpdomains.size(); ++i) {

        bool dotInStr = true;
        string s = cpdomains[i];
        s = s.erase(0, s.find(' ')+1);
        int num = stoi(cpdomains[i].erase(cpdomains[i].find(' ')));

        while(dotInStr){
            if(s.find('.') == string::npos ){
                dotInStr = false;
            }
            cpDomainMap[s] += num;
            s = s.erase(0, s.find('.')+1);


        }
        cout << endl << endl;

    }
    vector<string> result;
    for (auto map = cpDomainMap.begin(); map != cpDomainMap.end(); ++map) {
        result.push_back(to_string(map->second) + " " + map->first);
    }

    return result;

}

int main(){

    vector<string> cpdomains = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    vector<string> result = subdomainVisits(cpdomains);

    for (auto res = result.begin(); res != result.end(); ++res) {
        cout << *res << endl;
    }

    return 0;
}