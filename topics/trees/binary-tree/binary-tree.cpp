//
// Created by Siddhant on 2019-10-02.
//

#include "binary-tree.h"

int main(){
    BinaryTree<int> b;
    b.create();

//    b.DisplayRoot();
    b.PreOrderTraversal();
    cout << "num of leaf nodes : " << b.CountLeafNodes() << endl;
}