//
// Created by Siddhant on 2019-09-07.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

void callAndPrint(int n){

    if(n > 0){
        callAndPrint(n-1);
        cout << "n : " << n << endl;
    }
}

void printAndcall(int n){

    if(n > 0){
        cout << "n : " << n << endl;
        printAndcall(n-1);
    }
}

int main(){

    cout << "\n\ncallAndPrint\n\n" ;
    callAndPrint(3);

    cout << "\n\nprintAndcall\n\n" ;
    printAndcall(3);

    return 0;
}