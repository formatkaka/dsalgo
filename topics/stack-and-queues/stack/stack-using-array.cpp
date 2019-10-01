//
// Created by Siddhant on 2019-09-30.
//

#include "stack-using-array.h"

int main(){
    Stack<int> s(4);
    s.Push(5);
    s.Push(11);
    s.Push(3);
    s.Push(3);

    s.Pop();
    s.Pop();

    s.Display();
}