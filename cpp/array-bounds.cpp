//
// Created by Siddhant on 2019-09-10.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int globalArr[2];

int main(){

    int arr[2];

    for (int i = 0; i < 5; ++i) {
//        arr[i] = i;
        globalArr[i] = i;
    }

    for (int i = 0; i < 5; ++i) {
        cout << "globalArr : " << globalArr[i] << endl;
    }

    return 0;
}
