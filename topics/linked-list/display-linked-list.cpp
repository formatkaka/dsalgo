//
// Created by Siddhant on 2019-09-27.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;

template <class T>
struct Node {
    T data;
    struct Node* next;
};

struct Node<int>* create(int A[], int n){

    struct Node<int>* p = new Node<int>;
    struct Node<int>* first = p;

    for (int i = 0; i < n; ++i) {
        p->data = A[i];
        p->next = i < n-1 ? new Node<int> : NULL;
        if(i < n-1){
            p = p->next;
        }
    }
    return first;

}

void DisplayLL(struct Node<int>* p){

    while(p){
        cout << p->data << endl;
        p = p->next;
    }

}

void DisplayLR(struct Node<int>* p){
    if(!p) return;

    cout << p->data << endl;
    DisplayLR(p->next);
}

int numOfNodes(struct Node<int>* p){
    int num = 0;
    while(p){
        p = p->next;
        num++;
    }
    cout << "Number of nodes are : " << num << endl;
    return num;
}

void sumOfNodes(struct Node<int>* p){
    int sum = 0;
    while(p){
        sum = sum + p->data;
        p = p->next;
    }
    cout << "Sum of nodes are : " << sum << endl;;
}

void largestNode(struct Node<int>* p, int currLargest){

    if(!p) {
        cout << "Largest Node is : " << currLargest << endl;
        return;
    }

    if(p->data > currLargest){
        currLargest = p->data;
    }
    p = p->next;
    largestNode(p, currLargest);
}

void searchInLL(struct Node<int>* p, int numToFind){
    int num = 0;
    while(p){
        if(p->data == numToFind){
            cout << "Found number on link number : " << num << endl;
            return;
        }
        p = p->next;
        num++;
    }
    cout << "Number not found in the list" << endl;
}

struct Node<int>* Insert(struct Node<int>* p, int index, int data){
    if(index < 0 || index > numOfNodes(p)) return p;
    struct Node<int>* newNode = new Node<int>;
    newNode->data = data;

    if(index==0){
        newNode->next = p;
        p = newNode;
    }else{

        while(index-1){
            p = p->next;
            index--;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    return p;



}

int main(){

    int A[] = {-91,27,34,43,6,55,3,1};

    // create
    struct Node<int>* p = create(A, 8);

    // display
    DisplayLR(p);

    // number of nodes
    numOfNodes(p);

    // sum of nodes
    sumOfNodes(p);

    // curr largest
    largestNode(p, INT_MIN);

    // search in list
    searchInLL(p, 55);

    // insert in ll
    p = Insert(p, 0, 23);
    DisplayLR(p);

    return 0;
}