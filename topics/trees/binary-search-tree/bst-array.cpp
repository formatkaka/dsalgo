//
// Created by Siddhant on 2019-11-18.
//

#include "bst-array.h"

#include "iostream"
#include "vector"
#include "string"

using namespace std;

int main(){

    BSTree b;
//    vector<int> vLevel = {5,1,8,2,7,10};
//    vector<int> vLevel = {10,5,40,4,7,50,3,2};
      vector<int> vLevel = {10,5,4,7,3,2};
      vector<int> vPreorder = {5,2,1-1,-2,4,3,7,8,9,10};
      vector<int> vPostorder = {5,7,8,2,4,3,1};


//    vector<int> vInorder = {1,2,3,4,5,6,7,8,9,10};
//    b.createUsingLevelOrder(v);
//    b.createUsingLevelOrderCompressed(vLevel);
//    b.createUsingInOrder(vInorder);
//      b.createUsingPreOrder(vPostorder);
      b.createUsingPostOrder(vPostorder);


//    b.inorder();
    b.deleteNode(b.head, 2);
    cout << endl << "Root val : " << b.head->val;
    return 0;
}