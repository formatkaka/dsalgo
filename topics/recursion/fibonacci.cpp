//
// Created by Siddhant on 2019-09-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

double memoize[10];

double Mfibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }

    cout << "n : " << n << " " << memoize[n] << endl;
    if(memoize[n] == 0){
        cout << "to calculate : " << n << " " << endl;
        double res = Mfibonacci(n-1) + Mfibonacci(n-2);
        memoize[n] = res;
    }
    return memoize[n];

}

double fibonacci(int n){
    if(n==1 || n==2){
        return 1;
    }

    cout << "to calculate : " << n << " " << endl;
    return fibonacci(n-1) + fibonacci(n-2);

}

int main(){

    int n;
    cout << "Enter n : " ;
    cin >> n;



//    cout << "Fibo normal : " << fibonacci(n) << endl << endl;
    cout << "Fibo memoized : " << Mfibonacci(n);

    return 0;
}