//
// Created by Siddhant on 2019-09-30.
//

#include "double-linked-list.h"

int main(){
    int A[] = {1,2,3,4};

    DoubleList<int> d(A, 4);
    d.Insert(2, 25);
//    cout << "delete : " << d.Delete(3) << endl;
    d.Reverse();
    d.Display();

}