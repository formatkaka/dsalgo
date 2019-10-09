//
// Created by Siddhant on 2019-10-05.
//

#include "avl-trees.h"

int main(){

    AVL a;

    a.RInsert();
    a.RInsert();
    a.RInsert();
//    a.RInsert();
//    a.RInsert();

    cout << "Root is : " << a.root->data << endl;
    cout << "Root lchild is : " << a.root->lchild->data << endl;
    cout << "Root rchild is : " << a.root->rchild->data;

}