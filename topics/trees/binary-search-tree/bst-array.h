//
// Created by Siddhant on 2019-11-18.
//

#ifndef DSALGO_BST_ARRAY_H
#define DSALGO_BST_ARRAY_H

#include "vector"
#include "iostream"
#include "queue"

using namespace std;

class BNode {
public:
    BNode *left;
    BNode *right;
    int val;

    BNode(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }
};

class BSTree {
private:

public:
    BSTree() {};

    BNode *head;

    void createUsingLevelOrder(vector<int> &input);

    void createUsingLevelOrderCompressed(vector<int> &input);

    void createUsingInOrder(vector<int> &input);

    void createUsingPreOrder(vector<int> &input);

    void createUsingPostOrder(vector<int> &input);

    void inorder() { inorder(head); };

    void inorder(BNode *);

    BNode* deleteNode(BNode* node,int val);

    BNode *findNode(int val);

    BNode *findInorderPredecessor(BNode *node);

    BNode *findInorderSucessor(BNode *node);

    BNode* updateNodeChildren(BNode *node);

};

void BSTree::createUsingLevelOrder(vector<int> &input) {

    queue<BNode *> q;
    int i = 0;
    head = new BNode(input[i]);
    q.push(head);

//    i++;
    int size = 1;

    while (!q.empty() && size < input.size()) {

        int _size = q.size();
        int temp = 0;
        for (int j = i; j < i + _size; j++) {
            BNode *node = q.front();
            q.pop();

            BNode *left = input[2 * j + 1] != -1 ? new BNode(input[2 * j + 1]) : NULL;
            BNode *right = input[2 * j + 2] != -1 ? new BNode(input[2 * j + 2]) : NULL;

            node->left = left;
            node->right = right;

            if (left) {
                q.push(left);
            }

            if (right) {
                q.push(right);
            }

            temp++;
            size += 2;
        }
        i += temp;
    }

}

// ref https://stackoverflow.com/questions/36195376/constructing-a-unique-binary-search-tree-from-level-order-traversal-output?rq=1

void BSTree::createUsingLevelOrderCompressed(vector<int> &input) {
    queue<pair<BNode *, int>> q;
    head = new BNode(input[0]);
    q.push(make_pair(head, INT_MAX));

    int i = 1;

    while (!q.empty() && i < input.size()) {

        int queue_size = q.size();

        for (int j = 0; j < queue_size; ++j) {

            BNode *node = q.front().first;
            int cutoffval = q.front().second;
            q.pop();

            if (input[i] < node->val) {
                BNode *lNode = new BNode(input[i++]);
                node->left = lNode;
                q.push(make_pair(lNode, node->val));
            }

            if (input[i] > node->val && input[i] < cutoffval) {
                BNode *rNode = new BNode(input[i++]);
                node->right = rNode;
                q.push(make_pair(rNode, cutoffval));
            }

            cout << "i : " << i << " , " << node->val << endl;
        }

    }

}

BNode *InorderRecursive(vector<int> &input, int s, int e) {

    if (s > e) {
        return NULL;
    }

    int mid = (s + e) / 2;
    BNode *node = new BNode(input[mid]);

    if (s == e) {
        return node;
    }

    node->left = InorderRecursive(input, s, mid - 1);
    node->right = InorderRecursive(input, mid + 1, e);

    return node;
}

void BSTree::createUsingInOrder(vector<int> &input) {

    head = InorderRecursive(input, 0, input.size() - 1);

}

BNode *PreOrderRecursive(vector<int> &input, int cutmin, int cutmax) {

    static int i = 0;

    if (i == input.size()) {
        return NULL;
    }

    BNode *node = new BNode(input[i]);
    int curr_val = input[i];
    i++;

    if (input[i] > cutmin && input[i] < cutmax) {

        if (i < input.size() && input[i] < curr_val) {
            node->left = PreOrderRecursive(input, cutmin, input[i - 1]);
        }

    }

    if (input[i] > cutmin && input[i] < cutmax) {

        if (i < input.size() && input[i] > curr_val) {
            node->right = PreOrderRecursive(input, input[i - 1], cutmax);
        }

    }

    return node;


}

void BSTree::createUsingPreOrder(vector<int> &input) {

    head = PreOrderRecursive(input, INT_MIN, INT_MAX);

}

BNode *PostOrderRecursive(vector<int> &input, int cutmin, int cutmax) {


    static int i = 0;

    if (i == input.size()) {
        return NULL;
    }

    BNode *node = new BNode(input[i]);
    int curr_val = input[i];
    i++;


    if (input[i] > cutmin && input[i] < cutmax) {

        if (i < input.size() && input[i] > curr_val) {
            node->right = PostOrderRecursive(input, input[i - 1], cutmax);
        }

    }

    if (input[i] > cutmin && input[i] < cutmax) {

        if (i < input.size() && input[i] < curr_val) {
            node->left = PostOrderRecursive(input, cutmin, input[i - 1]);
        }

    }


    return node;

}

void BSTree::createUsingPostOrder(vector<int> &input) {

    head = PostOrderRecursive(input, INT_MIN, INT_MAX);

}

void BSTree::inorder(BNode *node) {

    if (!node) {
        return;
    }

    inorder(node->left);
    cout << node->val << ", ";
    inorder(node->right);

}

BNode *BSTree::findInorderPredecessor(BNode *node) {

    BNode *left = node->left;

    while (left && left->right) {
        left = left->right;
    }

    return left;

}

BNode *BSTree::findInorderSucessor(BNode *node) {

    BNode *right = node->right;

    while (right && right->left) {
        right = right->left;
    }

    return right;

}

BNode *BSTree::findNode(int val) {

    BNode *node = head;

    while (node) {

        if (node->val > val) {
            node = node->left;
        }else if (node->val < val) {
            node = node->right;
        }else {
            return node;
        }

    }

    return node;

}

BNode* BSTree::updateNodeChildren(BNode *node) {


    BNode *suc = findInorderSucessor(node);
    BNode *pre = findInorderPredecessor(node);

    if(!node){
        return NULL;
    }

    if(!node->left && !node->right){
        free(node);

        return NULL;
    }

    if (suc) {

        node->val = suc->val;
        node->left = updateNodeChildren(suc);

    } else if (pre) {

        node->val = pre->val;
        node->right = updateNodeChildren(pre);

    }

    return node;

}

BNode* BSTree::deleteNode(BNode* node,int val) {

    if(!node){
        return NULL;
    }

    if(!node->left && !node->right){

        if(head == node){
            head = NULL;
        }

        delete node;
        return NULL;

    }

    if(val > node->val){
        node->right = deleteNode(node->right, val);
    }else if(val < node->val){
        node->left = deleteNode(node->left, val);
    }else{

        BNode* suc = findInorderSucessor(node);

       if(suc){
           node->val = suc->val;
           node->right = deleteNode(node->right, suc->val);
       }else{
           BNode* pre = findInorderPredecessor(node);
           node->val = pre->val;
           node->left = deleteNode(node->left, pre->val);
       }

    }

    return node;

}

#endif //DSALGO_BST_ARRAY_H
