//
// Created by Siddhant on 2019-09-09.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int power(int base, int index){
    if(index == 0) return 1;

    if(index > 0) {
        return base*power(base, index-1);
    }

}

int Ipower(int base, int index){
    int output = 1;

    const int BASE_CASE_VALUE = 1;

    for (int i = 0; i <= index; ++i) {
        // Skip i = 0
        int multiplier = i == 0 ? BASE_CASE_VALUE : base ;
        output *= multiplier;
    }

    return output;
}

int main(){
    int base, radix;
    cout << "Enter base and radix : " ;
    cin >> base >> radix;

    cout << "Output Recursion : " << power(base, radix) << endl ;
    cout << "Output Iteration : " << Ipower(base, radix) ;

    return 0;
}