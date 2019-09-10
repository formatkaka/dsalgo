//
// Created by Siddhant on 2019-09-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int sum(int n){
    if(n == 0) return 0;
    if(n > 0){
        return sum(n-1) + n;
    }
}

int ISum(int n){

    int output = 0;
    for (int i = 0; i <= n; ++i) {
        output += i;
    }

    return output;

}

int main(){

    int n;
    cout << "Enter n : " ;
    cin >> n;

    cout << "Output Recursion : " << sum(n) << endl ;
    cout << "Output Iteration : " << ISum(n) ;

    return 0;
}