//
// Created by Siddhant on 2019-10-05.
//

#ifndef DSALGO_AVL_TREES_H
#define DSALGO_AVL_TREES_H

#include "iostream"

using namespace std;

class NodeAVL {
public:
    NodeAVL *lchild;
    NodeAVL *rchild;
    int height;
    int data;
};

class AVL {
private:

public:
    NodeAVL *root = NULL;
    AVL() {};

    ~AVL() {};

    void create();

    NodeAVL *RInsert(NodeAVL *p, int key);

    int NodeHeight(NodeAVL *p);

    int BalanceFactor(NodeAVL *p);

    void RInsert();
    NodeAVL* LRRotation(NodeAVL *p);
    NodeAVL* LLRotation(NodeAVL *p);
};

int AVL::NodeHeight(NodeAVL *p) {
    int hl = p && p->lchild ? p->lchild->height : 0;
    int hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVL::BalanceFactor(NodeAVL *p) {
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    return hl - hr;
}

NodeAVL* AVL::LRRotation(NodeAVL *p) {

    NodeAVL* pl = p->lchild;
    NodeAVL* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    // Is this order important ?
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root  = plr;

    return plr;

}

NodeAVL* AVL::LLRotation(NodeAVL *p) {
    NodeAVL *pl = p->lchild;

    p->lchild = pl->rchild;
    pl->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if(root == p)
        root = pl;

    return pl;

}

void AVL::RInsert(){
    int data;
    cout << "Enter key : " ;
    cin >> data;

    root = RInsert(root, data);
}

NodeAVL *AVL::RInsert(NodeAVL *p, int key) {

    if (!p) {
        NodeAVL *newNode = new NodeAVL;
        newNode->data = key;
        newNode->lchild = NULL;
        newNode->rchild = NULL;
        newNode->height = 1;
        return newNode;
    }

    if (key > p->data) {
        p->rchild = RInsert(p->rchild, key);
    } else {
        p->lchild = RInsert(p->lchild, key);
    }

    p->height = NodeHeight(p);
    int balanceFactor = BalanceFactor(p);

    if(balanceFactor==2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    if(balanceFactor==2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p);


    return p;

}



#endif //DSALGO_AVL_TREES_H
