//
// Created by Siddhant on 2019-10-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int arr[100] = {0};

int FibonacciDP(int n){
    if(n == 0 || n == 1){
        return n;
    }

    if(arr[n] > 0){
        return arr[n];
    }

    arr[n] = FibonacciDP(n-1) + FibonacciDP(n-2);

    return arr[n];

}

int Fibonacci(int n){
    if(n == 0){
        return 0;
    }else if(n == 1){
        return 1;
    }

    int p1 = 0;
    int p2 = 1;

    for (int i = 0; i <= n-2; ++i) {
        int sum = p1+p2;
        p1 = p2;
        p2 = sum;
    }

    return p2;

}

int main(){

    int fib;
    cout << "Enter n : " ;
    cin >> fib;

    cout << "Fib(" << fib << ") is : " << FibonacciDP(fib);

    return 0;
}