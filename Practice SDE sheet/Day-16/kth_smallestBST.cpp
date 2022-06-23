#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void inorder(TreeNode<int>* root, priority_queue<int,vector<int>, greater<int>> &heap){
    if(root == NULL){
        return;
    }
    inorder(root->left,heap);
    heap.push(root->data);
    inorder(root->right,heap);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    priority_queue<int,vector<int>, greater<int>> heap;
    inorder(root,heap);
    if(heap.size() < k) return -1;
    int temp = -1;
    while(k--){
        temp = heap.top();
        heap.pop();
    }
    return temp;
}
