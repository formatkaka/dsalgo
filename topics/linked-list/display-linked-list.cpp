//
// Created by Siddhant on 2019-09-27.
//

#include "iostream"
#include "vector"
#include "string"

using namespace std;


struct Node {
    int data;
    struct Node *next;
} *first = NULL;

struct Node *create(int A[], int n) {

    struct Node *p = new Node;
    struct Node *first = p;

    for (int i = 0; i < n; ++i) {
        p->data = A[i];
        p->next = i < n - 1 ? new Node : NULL;
        if (i < n - 1) {
            p = p->next;
        }
    }
    return first;

}

void DisplayLL(struct Node *p) {

    while (p) {
        cout << p->data << endl;
        p = p->next;
    }

}

void DisplayLR(struct Node *p) {
    if (!p) return;

    cout << p->data << endl;
    DisplayLR(p->next);
}

int numOfNodes(struct Node *p) {
    int num = 0;
    while (p) {
        p = p->next;
        num++;
    }
    cout << "Number of nodes are : " << num << endl;
    return num;
}

void sumOfNodes(struct Node *p) {
    int sum = 0;
    while (p) {
        sum = sum + p->data;
        p = p->next;
    }
    cout << "Sum of nodes are : " << sum << endl;;
}

void largestNode(struct Node *p, int currLargest) {

    if (!p) {
        cout << "Largest Node is : " << currLargest << endl;
        return;
    }

    if (p->data > currLargest) {
        currLargest = p->data;
    }
    p = p->next;
    largestNode(p, currLargest);
}

int searchInLL(struct Node *p, int numToFind) {
    int num = 0;
    while (p) {
        if (p->data == numToFind) {
            cout << "Found number on link number : " << num << endl;
            return num;
        }
        p = p->next;
        num++;
    }
    cout << "Number not found in the list" << endl;
    return -1;
}

void insertInSortedList(struct Node *p, int numToInsert) {

    struct Node *q = p->next;
    struct Node *newNode = new Node;
    newNode->data = numToInsert;
    newNode->next = NULL;

    if (numToInsert < p->data) {
        newNode->next = p;
        first = newNode;
        return;
    }

    while (p && q) {

        if (numToInsert > p->data && numToInsert < q->data) {
            newNode->next = q;
            p->next = newNode;
            return;
        }

        p = p->next;
        q = q->next;
    }

    p->next = newNode;

}

struct Node *Insert(struct Node *p, int index, int data) {
    if (index < 0 || index > numOfNodes(p)) return p;
    struct Node *newNode = new Node;
    newNode->data = data;

    if (index == 0) {
        newNode->next = p;
        p = newNode;
    } else {

        while (index - 1) {
            p = p->next;
            index--;
        }
        newNode->next = p->next;
        p->next = newNode;
    }

    return p;


}

void deleteFromList(int num, bool isIndex) {

    if (!isIndex) {
        num = searchInLL(first, num);
        if (num == -1) return;
    }

    if (num == 0) {
        struct Node *temp = first->next;
        delete first;
        first = temp;
        return;
    }

    struct Node *p = first;
    for (int i = 0; i < num - 1; ++i) {
        p = p->next;
    }

    struct Node *temp = p->next->next;
    delete p->next;
    p->next = temp;

}

void isListSorted(struct Node *p) {

    while (p) {

        if (p->next && p->data > p->next->data) {
            cout << "List is not sorted" << endl;
            return;
        }
        p = p->next;
    }
    cout << "List is sorted" << endl;

}

void reverseList(struct Node *p) {
    struct Node *curr = p, *next = p->next, *prev = NULL;

    while (curr) {

        curr->next = prev;
        prev = curr;
        if (next) {
            curr = next;
            next = curr->next;
        } else {
            break;
        }
    }

    first = prev;

}

void RevursiveRev(struct Node *next, struct Node *curr) {
    if (curr) {
        RevursiveRev(curr, curr->next);
        curr->next = next;
    } else {
        first = next;
    }
}

struct Node* mergeLists(struct Node* p1, struct Node* p2){

    struct Node *third, *last;

    if(p1->data < p2->data){
        third = last = p1;
        p1 = p1->next;
        last->next = NULL;
    }else{
        third = last = p2;
        p2 = p2->next;
        last->next = NULL;
    }

    while(p1 && p2){

        if(p1->data < p2->data){
            last->next = p1;
            last = p1;
            p1 = p1->next;
            last->next = NULL;
        }else{
            last->next = p2;
            last = p2;
            p2 = p2->next;
            last->next = NULL;
        }

    }

    if(p1){
        last->next = p1;
    }else{
        last->next = p2;
    }

    last->next = third->next;

    return third;

}

bool detectLoop(struct Node* p){
    struct Node *slow = p, *fast = p;

    while(slow && fast){

        slow = slow->next;
        if(!slow) return false;

        fast = fast->next;
        if(fast->next){
            fast = fast->next;
        }else{
            return false;
        }

        if(slow->data == fast->data){
            cout << "same data : " << fast->data << endl;
            return true;
        }

    }

}

int main(){

    int A[] = {-91, 1, 30, 67};
    int B[] = {0, 11, 34, 60};

    struct Node*p = create(A, 4);
    struct Node*q = create(B, 4);
    struct Node*r = create(B, 4);

    struct Node* head = mergeLists(p, q);
//    DisplayLR(head);

    cout << "Is there loop : " << detectLoop(head);

}













//int main() {
//
//    int A[] = {-91, 1, 3, 6, 22, 34, 66, 78};
//
//    // create
//    struct Node *p = create(A, 8);
//    first = p;
//    // display
//    DisplayLR(p);
//
//    // number of nodes
//    numOfNodes(p);
//
//    // sum of nodes
//    sumOfNodes(p);
//
//    // curr largest
//    largestNode(p, INT_MIN);
//
//    // search in list
//    searchInLL(p, 55);
//
////    DisplayLR(first);
//
//    // delete from list
//    deleteFromList(-92, false);
//    deleteFromList(-91, false);
//    DisplayLR(first);
//
//    isListSorted(first);
//
//    // reverseList
////    reverseList(p);
//    RevursiveRev(first, first->next);
//    DisplayLR(first);
//
//    return 0;
//}