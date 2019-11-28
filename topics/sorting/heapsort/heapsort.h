//
// Created by Siddhant on 2019-11-24.
//

#ifndef DSALGO_HEAPSORT_H
#define DSALGO_HEAPSORT_H

#include "iostream"
#include "vector"
#include "string"


using namespace std;

template <class T>
class Heap{

    vector<T> heap;
    int heap_size;
    void max_heapify(int key);

    void build_max_heap(vector<T> input);

public:

    Heap(vector<T> input);

    vector<T> getSortedList();

    T getTop();

};

template <class T>
void Heap<T>::max_heapify(int key) {

    if(key >= heap_size/2){
        return;
    }

    int largest = key;

    int left = 2*key + 1;
    int right = 2*key + 2;

    if(heap[largest] < heap[left] ){
//        swap(heap[largest], heap[left]);
        largest = left;
    }

    if(heap[largest] < heap[right]){
//        swap(heap[largest], heap[right]);
        largest = right;
    }

    if(largest != key){
        swap(heap[largest], heap[key]);
        max_heapify(largest);
    }

}

template <class T>
void Heap<T>::build_max_heap(vector<T> input) {

    heap_size = 2;
    heap = input;

    for (int i = (input.size()/2)-1; i >= 0; --i) {
        max_heapify(i);
    }

}

template <class T>
Heap<T>::Heap(vector<T> input) {

    build_max_heap(input);

}

template <class T>
T Heap<T>::getTop() {

    return heap[0];

}

#endif //DSALGO_HEAPSORT_H
