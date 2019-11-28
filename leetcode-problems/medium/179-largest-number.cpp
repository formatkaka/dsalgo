//
// Created by Siddhant on 2019-11-25.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

bool compare(int n1, int n2){

    string s1 = to_string(n1);
    string s2 = to_string(n2);

    return s1+s2 > s2+s1;

//    int i = 0;
//
//    while(i < s1.length() && i < s2.length()){
//
//        if(s1[i] != s2[i]){
//            return s1[i] > s2[i];
//        }
//
//        i++;
//
//    }
//
//    // when same
//    if(s1.length() == s2.length()){
//        return true;
//    }
//
//    if(i == s1.length()){
//        return s1[i-1] > s2[i];
//    }
//
//    return s1[i] > s2[i-1];


}

int main(){

    vector<int> v = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1};
    sort(v.begin(), v.end(), compare);
    string res = "";

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " " ;
        res += to_string(v[i]);
    }

    cout << endl << res;

    return 0;
}