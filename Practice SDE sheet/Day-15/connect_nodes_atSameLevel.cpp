#include<bits/stdc++.h>
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    queue<BinaryTreeNode< int > *> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        BinaryTreeNode< int > * prev = NULL;
        while(sz--){
            BinaryTreeNode< int > * node = q.front();
            q.pop();
            node->next = prev;
            prev = node;
            if(node->right!=NULL){
                q.push(node->right);
            }
            if(node->left!=NULL){
                q.push(node->left);
            }
        }
    }
}