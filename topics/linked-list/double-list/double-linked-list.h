//
// Created by Siddhant on 2019-09-30.
//

#ifndef DSALGO_LINKED_LIST_H
#define DSALGO_LINKED_LIST_H

#include "iostream"
#include "../circular-list/linked-list.h"

using namespace std;

template<class T>
class Node {
public:
    Node *prev;
    T data;
    Node *next;
};

template<class T>
class DoubleList {
private:
    Node<T> *first;
public:
    DoubleList() {
        first->next = NULL;
        first->prev = NULL;
    }

    DoubleList(T A[], int len);

    ~DoubleList();

    void Display();

    int Length();

    void Insert(int index, T data);

    int Delete(int index);

    void Reverse();
};

template<class T>
DoubleList<T>::DoubleList(T *A, int len) {
    first = new Node<T>;
    first->data = A[0];
    first->prev = NULL;
    first->next = NULL;

    Node<T> *last = first;

    for (int i = 1; i < len; ++i) {

        Node<T> *t = new Node<T>;
        t->data = A[i];

        last->next = t;
        t->prev = last;
        t->next = NULL;
        last = t;
    }
}

template<class T>
DoubleList<T>::~DoubleList() {}

template<class T>
int DoubleList<T>::Length() {

    Node<T> *t = first;
    int len = 0;
    while (t) {
        len++;
        t = t->next;
    }
    return len;
}

template<class T>
void DoubleList<T>::Insert(int index, T data) {
    if (index < 0 || index > Length()) return;

    Node<T> *newNode = new Node<T>;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = first;
        first->prev = newNode;
        first = newNode;
    } else {
        Node<T> *t = first;
        for (int i = 0; i < index - 1; ++i) {
            t = t->next;
        }

        newNode->next = t->next;
        newNode->prev = t;
        t->next->prev = newNode;
        t->next = newNode;

    }
}

template<class T>
int DoubleList<T>::Delete(int index) {
    if (index < 0 || index > Length()) return INT_MIN;
    int data;
    Node<T> *t = first;

    if (index == 0) {
        data = first->data;
        first = t->next;
        first->prev = NULL;
        delete t;
    } else {
        for (int i = 0; i < index - 1; ++i) {
            t = t->next;
        }
        Node<T> *toDel = t->next;
        data = toDel->data;
        t->next = t->next->next;

        if (t->next) {
            t->next->prev = t;
        }
    }

    return data;
}

template <class T>
void DoubleList<T>::Reverse(){
    Node<T>* t = first;

    while(t){
        Node<T>* k = t->prev;
        t->prev = t->next;
        t->next = k;
        t = t->prev;
        if(t && !t->next){
            cout << "final " ;
            first = t;
        }
    }

}

template<class T>
void DoubleList<T>::Display() {

    Node<T> *t = first;

    while (t) {
        cout << t->data << " ";
        t = t->next;
    }
}


#endif //DSALGO_LINKED_LIST_H
