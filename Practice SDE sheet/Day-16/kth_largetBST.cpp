#include<bits/stdc++.h>
/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, priority_queue<int> &heap){
    if(root == NULL){
        return;
    }
    inorder(root->left,heap);
    heap.push(root->data);
    inorder(root->right,heap);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    priority_queue<int> heap;
    inorder(root,heap);
    if(heap.size() < k) return -1;
    int temp = -1;
    while(k--){
        temp = heap.top();
        heap.pop();
    }
    return temp;
}
