//
// Created by Siddhant on 2019-10-02.
//

#ifndef DSALGO_BINARY_SEARCH_TREE_H
#define DSALGO_BINARY_SEARCH_TREE_H

#include "iostream"

using namespace std;

template<class T>
class Node {
public:
    Node *lchild;
    T data;
    Node *rchild;
};

template<class T>
class BST {
private:
    Node<T> *root;

    Node<T> *createNewNode(T data);

public:
    BST() {};

    ~BST() {};

    void create();

    bool Delete();

    void Delete(Node<T> *p, T key);

    bool Insert();

    bool Search();

    void InOrderTraversal() {
        InOrderTraversal(root);
        cout << endl;
    };

    void InOrderTraversal(Node<T> *r);

    int RangeSum(int L, int R) {
        return RangeSum(root, L, R);
    };

    int RangeSum(Node<T> *, int, int);
};

template<class T>
Node<T> *BST<T>::createNewNode(T data) {
    Node<T> *t = new Node<T>;
    t->data = data;
    t->lchild = NULL;
    t->rchild = NULL;

    return t;
}

template<class T>
void BST<T>::create() {
    T rootInp;
    cout << "Enter root node : ";
    cin >> rootInp;

    Node<T> *rootNode = createNewNode(rootInp);

    root = rootNode;

    bool breakInputLoop = false;
    while (!breakInputLoop) {
        bool insertSuccessfull = Insert();
        breakInputLoop = !insertSuccessfull;
    }
}

template<class T>
bool BST<T>::Insert() {
    T data;
    cout << "Enter Node Data : ";
    cin >> data;

    if (data == -1) {
        return false;
    }

    Node<T> *t = createNewNode(data);
    Node<T> *p = root;
    bool newNodeAdded = false;

    while (!newNodeAdded) {

        if (data > p->data) {

            if (!p->rchild) {
                p->rchild = t;
                newNodeAdded = true;
            } else {
                p = p->rchild;
            }
        } else {
            if (!p->lchild) {
                p->lchild = t;
                newNodeAdded = true;
            } else {
                p = p->lchild;
            }

        }

    }

    return true;


}

template<class T>
bool BST<T>::Delete() {
    T data;
    cout << "Enter value to delete : ";
    cin >> data;
    Delete(root, data);
}


template<class T>
void BST<T>::Delete(Node<T> *p, T key) {

    if (!p->lchild && !p->rchild) return;

    if (key == p->data) {
        // delete link from parent
//        delete p;
//        return true;
        Node<T> *x;
        if (Height(p->lchild) > Height(p->rchild)) {
            x = InSucc(p->rchild);
            Delete(x, x->data);
        } else {
            x = InPre(p->lchild);
            Delete(x, x->data);
        }

        p->data = x->data;
        return;
    }

    if (key > p->data) {
        Delete(p->rchild, key);
    } else {
        Delete(p->lchild, key);
    }

}

template<class T>
bool BST<T>::Search() {
    T data;
    cout << "Enter value to search : ";
    cin >> data;

    Node<T> *p = root;

    while (p) {

        if (p->data == data) {
            cout << "Found number";
            return true;
        }

        if (data > p->data) {
            p = p->rchild;
        } else {
            p = p->lchild;
        }

    }

    cout << "Not found number";
    return false;
}

template<class T>
void BST<T>::InOrderTraversal(Node<T> *r) {
    if (r) {
        InOrderTraversal(r->lchild);
        cout << r->data << " ";
        InOrderTraversal(r->rchild);
    }
}

template<class T>
int BST<T>::RangeSum(Node<T> *p, int L, int R) {
    // Q938 leetcode
    if (!p) {
        return 0;
    }
    int recsum = 0;
    if (p->data <= L) {
        recsum = RangeSum(p->rchild, L, R);
    } else if (p->data >= R) {
        recsum = RangeSum(p->lchild, L, R);
    } else {
        int lsum = RangeSum(p->lchild, L, R);
        int rsum = RangeSum(p->rchild, L, R);
        recsum = lsum + rsum;
    }

    int nodeAdditionVal = 0;

    if (p->data >= L && p->data <= R) {
        nodeAdditionVal = p->data;
    }

    return nodeAdditionVal + recsum;

}

#endif //DSALGO_BINARY_SEARCH_TREE_H
