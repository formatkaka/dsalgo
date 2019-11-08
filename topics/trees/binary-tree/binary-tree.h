//
// Created by Siddhant on 2019-10-02.
//

#ifndef DSALGO_BINARY_TREE_H
#define DSALGO_BINARY_TREE_H

#include "queue"
#include "iostream"


using namespace std;

template<class T>
class NodeB {
public:
    NodeB *lchild;
    T data;
    NodeB *rchild;
};

template<class T>
class BinaryTree {
private:
    NodeB<T> *root = new NodeB<T>;
public:
    BinaryTree() {};

    void create();

    void DisplayRoot();

    void InOrderTraversal() {
        InOrderTraversal(root);
        cout << endl;
    };

    void InOrderTraversal(NodeB<T> *r);

    void PreOrderTraversal() {
        PreOrderTraversal(root);
        cout << endl;
    };

    void PreOrderTraversal(NodeB<T> *r);

    string serialize();

    int TreeHeight() { return TreeHeight(root); };

    int TreeHeight(NodeB<T> *r);

    int CountLeafNodes() { return CountLeafNodes(root); };

    int CountLeafNodes(NodeB<T> *r);
//    void PreOrderTraversal();
//    void PostOrderTraversal();
//    void LevelOrderTraversal();

};


template<class T>
void BinaryTree<T>::create() {
    queue<NodeB<T> *> createQueue;

    cout << "Enter root node : ";
    cin >> root->data;
    root->lchild = NULL;
    root->rchild = NULL;

    createQueue.push(root);

    while (!createQueue.empty()) {
        NodeB<T> *r = createQueue.front();
        createQueue.pop();

        // Left input
        T ldata;
        cout << "Enter l child for node data " << r->data << " : ";
        cin >> ldata;
        if (ldata != -1) {

            NodeB<T> *left = new NodeB<T>;
            left->data = ldata;
            left->lchild = NULL;
            left->rchild = NULL;
            r->lchild = left;
            createQueue.push(left);

        }

        // Left input
        T rdata;
        cout << "Enter r child for node data " << r->data << " : ";
        cin >> rdata;
        if (rdata != -1) {

            NodeB<T> *right = new NodeB<T>;
            right->data = rdata;
            right->lchild = NULL;
            right->rchild = NULL;
            r->rchild = right;
            createQueue.push(right);

        }

    }

}

template<class T>
void BinaryTree<T>::PreOrderTraversal(NodeB<T> *r) {
    if (r) {
        cout << r->data;
        InOrderTraversal(r->lchild);
        InOrderTraversal(r->rchild);
    }
}

template<class T>
void BinaryTree<T>::InOrderTraversal(NodeB<T> *r) {

    if (r) {
        InOrderTraversal(r->lchild);
        cout << r->data;
        InOrderTraversal(r->rchild);
    }
}

template<class T>
void BinaryTree<T>::DisplayRoot() {
    cout << "root : " << root->data;
}

template<class T>
int BinaryTree<T>::TreeHeight(NodeB<T> *r) {

    if (!r) {
        return 0;
    }

    int lH = TreeHeight(r->lchild);
    int rH = TreeHeight(r->rchild);

    return lH > rH ? lH + 1 : rH + 1;
}

template<class T>
int BinaryTree<T>::CountLeafNodes(NodeB<T> *r) {

    if (!r) {
        return 0;
    }

    int x = CountLeafNodes(r->lchild);
    int y = CountLeafNodes(r->rchild);

    return x + y +(!r->rchild && !r->lchild ? 1 : 0);
}

template<class T>
string BinaryTree<T>::serialize(){
    queue<NodeB<T>*> q;

        q.push(root);

        string serializedString = "[";

        while(!q.empty()){

            NodeB<T>* temp = q.front();
            q.pop();

            string val = temp->data ? to_string(temp->data) + ',' : "null,";

            serializedString = serializedString + val;

            if(temp->data == INT_MAX){
                continue;
            }

            if(temp->lchild){
                q.push(temp->lchild);
            }else{
                NodeB<T>* templeft;
                 templeft->data = INT_MAX;
                q.push(templeft);
            }

            if(temp->rchild){
                q.push(temp->rchild);
            }else{
                NodeB<T>* tempright;
                 tempright->data = INT_MAX;
                q.push(tempright);
            }

        }

        serializedString += ']';
        cout << "string : " << serializedString ;
        return serializedString;
}

#endif //DSALGO_BINARY_TREE_H
