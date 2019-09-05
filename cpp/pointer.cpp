//
// Created by Siddhant on 2019-09-03.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    int a = 10; // DATA VARIABLE
    int *p; // ADDRESS VARIABLE ( also called as pointers in C/C++ )
    p = &a;

    std::cout << "a directly : " << a << endl;

    std::cout << "a using pointer : " << *p << endl; // DEREFERENCING P

    return 0;
}