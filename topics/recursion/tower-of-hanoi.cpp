//
// Created by Siddhant on 2019-09-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

double tower_of_hanoi(int n){
    if(n==1){
        return 1;
    }
    
    return 2*tower_of_hanoi(n-1) + 1;
}

int main(){

    int n;
    cout << "Enter n : " ;
    cin >> n;
    
    cout << "Num of steps required are : " << tower_of_hanoi(n) ;
    return 0;
}