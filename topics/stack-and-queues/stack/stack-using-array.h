//
// Created by Siddhant on 2019-09-30.
//

#ifndef DSALGO_STACK_USING_ARRAY_H
#define DSALGO_STACK_USING_ARRAY_H

#include "iostream"

template <class T>
class Stack{
private:
    int size;
    int top;
    int *S;
public:
    Stack(int stackSize);
    ~Stack();
    
    bool Push(T data);
    bool Pop();
    T Peek(int index);
    T StackTop();
    bool isEmpty();
    bool isFull();
    void Display();
};

template <class T>
Stack<T>::Stack(int stackSize) {
    size = stackSize;
    top = -1;
//    int Arr[size] = {0};
    S = new T[size];
}

template <class T>
Stack<T>::~Stack() {}

template <class T>
bool Stack<T>::isFull() {
    return top==(size-1);
}

template <class T>
bool Stack<T>::isEmpty() {
    return top==-1;
}

template <class T>
bool Stack<T>::Push(T data) {
    if(isFull()) return false;
    
    top++;
    S[top] = data;
}

template <class T>
bool Stack<T>::Pop() {
    if(isEmpty()) return false;
    
    S[top] = INT_MIN;
    top--;
}

template <class T>
T Stack<T>::Peek(int index) {
    return S[size-index];
} 

template <class T>
T Stack<T>::StackTop() {
    return S[top-1];
}

template <class T>
void Stack<T>::Display() {
    for (int i = 0; i <= top; ++i) {
        std::cout << S[i] << " ";
    }
    std::cout << std::endl;
}

#endif //DSALGO_STACK_USING_ARRAY_H
