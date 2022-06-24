#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
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
bool isLeaf(TreeNode<int>* root){
    if(root->left == NULL && root->right == NULL){
        return true;
    }
    return false;
}
void addLeftBoundary(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    TreeNode<int>* node = root->left;
    while(node!=NULL){
        if(!isLeaf(node)){
            ans.push_back(node->data);
        }
        if(node->left!=NULL){
            node = node->left;
        }
        else{
            node = node->right;
        }
    }
}
void addLeaves(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}
void addRightBoundary(TreeNode<int>* root, vector<int> &ans){
    if(root == NULL) return;
    stack<int> st;
    TreeNode<int>* node = root->right;
    while(node!=NULL){
        if(!isLeaf(node)) st.push(node->data);
        if(node->right!=NULL){
            node = node->right;
        }
        else{
            node = node->left;
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundary(root,ans);
    addLeaves(root,ans);
    addRightBoundary(root,ans);
    return ans;
}