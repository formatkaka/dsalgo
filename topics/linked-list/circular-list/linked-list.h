//
// Created by Siddhant on 2019-09-30.
//

#ifndef DSALGO_LINKED_LIST_H
#define DSALGO_LINKED_LIST_H

#include "iostream"

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node *next;
};

template<class T>
class CircularLinkedList {
private:
    Node<T> *first;
public:

    CircularLinkedList() { first = NULL; }

    CircularLinkedList(T A[], int len);

    ~CircularLinkedList();

    void Display();
    void RDisplay(Node<T> *p);
    void Insert(int index, T data);
    int Delete(int index);
    int Length();
};

template<class T>
CircularLinkedList<T>::CircularLinkedList(T *A, int len) {
    Node<T> *last, *t = new Node<T>;

    first = new Node<T>;
    first->data = A[0];
    first->next = first;
    last = first;

    for (int i = 1; i < len; ++i) {
        t = new Node<T>;
        t->next = first;
        t->data = A[i];
        last->next = t;
        last = t;
    }

}

template<class T>
CircularLinkedList<T>::~CircularLinkedList() {
}

template <class T>
void CircularLinkedList<T>::Insert(int index, T data) {

    if(index < 0 || index > Length()) return;
    Node<T>* newNode = new Node<T>;
    newNode->data = data;
    newNode->next = NULL;

    if(index == 0){
        Node<T>* last = first;

        if(!first){
            first = newNode;
            first->next = first;
            return;
        }

        while(last->next != first){
            last = last->next;
        }

        last->next = newNode;
        newNode->next = first;
        first = newNode;

        return;
    }

    Node<T>*p = first;
    for (int i = 0; i < index - 1; ++i) {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;

}

template <class T>
int CircularLinkedList<T>::Delete(int index){
    if(index < 0 || index > Length()) return INT_MIN;

    if(index == 0){

    }

}

template <class T>
int CircularLinkedList<T>::Length() {
    Node<T> *p = first;
    int length = 0;
    do {
        length++;
        p = p->next;
    }while(p!=first);

    return length;
}

template<class T>
void CircularLinkedList<T>::Display() {
    Node<T> *p = first;
    do {
        cout << p->data << " ";
        p = p->next;
    }while(p!=first);
    cout << endl;
//    RDisplay(first);
}

template <class T>
void CircularLinkedList<T>::RDisplay(Node<T>* p){
    static int flag = 0;
    if(p==first && flag ){
        flag = 0;
        cout << endl;
        return;
    }
    flag = 1;
    cout << p->data << " " ;
    RDisplay(p->next);
}

#endif //DSALGO_LINKED_LIST_H
