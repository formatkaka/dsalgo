//
// Created by Siddhant on 2019-09-11.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array *arr){
    cout << "Print started " << endl;
    for (int i = 0; i < arr->length; ++i) {
        cout << i << " " << arr->A[i] << endl;
    }
    cout << "Print ended " << endl;
}

bool Append(struct Array *arr, int inputVal){

    if(arr->length == arr->size) return false;

    arr->A[arr->length++] = inputVal;
}

bool Insert(struct Array *arr, int inputVal, int index){
    if(index>=0 && index <=arr->length) {
        for (int i = arr->length; i > index; i--) {
            arr->A[i] = arr->A[i - 1];
        }
        arr->A[index] = inputVal;
        arr->length++;
    }
}

bool Delete(struct Array *arr, int index){
    if(index >= 0 && index <= arr->length){
        for (int i = index; i < arr->length; i++) {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
    }
}

int main(){

    struct Array arr = {{2,3,4,5,6},10,5};
    Display(&arr);
    Append(&arr, -5);
    Insert(&arr, 0, 0);
    Display(&arr);
    Delete(&arr,2);
    Display(&arr);
    return 0;
}

/*
 * Mistake :
 *
 * 1. Append, Insert were working on copy of struct object. Need to pass by reference.
 */