//
// Created by Siddhant on 2019-09-30.
//

#include "linked-list.h"

int main() {
    int A[] = {1, 2, 3, 4};
    CircularLinkedList<int> l(A, 4);

    l.Insert(0, 25);
    l.Display();
}