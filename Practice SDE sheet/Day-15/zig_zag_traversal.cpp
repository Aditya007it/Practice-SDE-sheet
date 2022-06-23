#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    queue<BinaryTreeNode<int> * > q;
    
    vector<int> ds;
    if(root == NULL) return ds;
    q.push(root);
    int level = 1;
    while(!q.empty()){
        int sz = q.size();
        vector<int> ans;
        while(sz--){
            BinaryTreeNode<int> * node = q.front();
            q.pop();
            ans.push_back(node->data);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        if(level%2==0){
            reverse(ans.begin(), ans.end());
        }
        for(auto &it: ans){
            ds.push_back(it);
        }
        level++;
        
    }
    return ds;
}
