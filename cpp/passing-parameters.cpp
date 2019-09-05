//
// Created by Siddhant on 2019-09-05.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int pass_by_address(int *a, int *b, int arr[]){ // declaration

    // definition
    int c;
    c = (*a) + (*b) ;
    cout << "arr : " << arr[0] << endl;
    return c;
}

int pass_by_reference(int &x, int &y){
    // not advisable as code is copy pasted in machine code
    return x+y;
}

int main(){

    int a = 1, b = 3;
    int arr[2] = {1,2};
    int out;

    out = pass_by_address(&a, &b, arr);
    int out_ref = pass_by_reference(a, b);


    cout << "out pass by param : " << out << endl;
    cout << "out_ref pass by param : " << out_ref << endl;

    return 0;
}