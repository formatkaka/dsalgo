//
// Created by Siddhant on 2019-09-19.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int numUniqueEmails(vector<string>& emails){

    vector<string> output;

    for (int i = 0; i < emails.size(); ++i) {
        string email = emails[i];
        string domain = email.substr(email.find('@'), email.size());
        //step1
        string p1 = email.substr(0, email.find('@'));
        string p2 = p1.substr(0, p1.find('+'));
        p2.erase(remove(p2.begin(), p2.end(), '.'), p2.end());

        string final = p2 + '@' + domain;
        auto it = find (output.begin(), output.end(), final);
        if(it == output.end()){
            output.push_back(final);
        }

    }

    return output.size();

}

int main(){

    vector<string> emails = {"test.emailalex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    cout << "Ans : " << numUniqueEmails(emails);
    return 0;
}