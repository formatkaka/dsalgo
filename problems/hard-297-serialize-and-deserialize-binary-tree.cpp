//
// Created by Siddhant on 2019-11-06.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath"

using namespace std;

pair<string, int> func(){
    return make_pair("a", 1);
}

int main(){

    cout << func().first << " second : " << func().second;
    double d = pow(2,100);
    cout << d;
    return 0;
}