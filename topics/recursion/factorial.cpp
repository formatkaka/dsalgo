//
// Created by Siddhant on 2019-09-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int factorial(int n){

    if(n == 0) return 1; // BASE_CASE

    if(n>0){
        return n*factorial(n-1);
    }
}

int Ifactorial(int n){

    int output = 1;
    const int BASE_CASE_VALUE = 1;
    for (int i = 0; i <= n; ++i) {
        // Skip i = 0
        int multiplier = i == 0 ? BASE_CASE_VALUE : i ;

        output *= multiplier;
    }

    return output;

}

int main(){

    int n;
    cout << "Enter n : " ;
    cin >> n;

    cout << "Output Recursion : " << factorial(n) << endl ;
    cout << "Output Iteration : " << Ifactorial(n) ;

    return 0;
}