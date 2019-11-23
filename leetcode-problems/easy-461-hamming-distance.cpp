//
// Created by Siddhant on 2019-09-12.
//

#include "iostream"
#include "vector"
#include "string"
#include "cmath";

using namespace std;
//string binary = "";
//
//string returnBinaryStructure(int num){
//
//    if(num==0) return "0";
//
//    if(num==1) return "1";
//
//
//
//}

int num1 = 0;

double returnNumOf1(int num){

    if(num==0) return 0;
    num1++;
    int lg = (int) log2(num);
    int foo = num - pow(2, lg);
    return returnNumOf1(foo);
}

int rotatingNumMethod(int num){

    // >> Right shift bitwise operator
    int count = 0;

    while(num!=0){
        if(num&1) count++;
        num = num >> 1;
    }

    return count;

}

int main(){

    int x = 1, y = 4;

    int diff = 9999;
    returnNumOf1(diff);
    cout << "My method : " << num1 << endl;
    cout << "Right shift method 1 : " << rotatingNumMethod(diff);

    return 0;
}