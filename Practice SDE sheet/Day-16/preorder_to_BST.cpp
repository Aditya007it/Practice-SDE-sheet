#include<bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int>* fun(vector<int> &arr, int low, int high){
    if(low > high){
        return NULL;
    }
    int mid = (low+high)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = fun(arr,low,mid-1);
    root->right = fun(arr,mid+1,high);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    sort(preOrder.begin(), preOrder.end());
    return fun(preOrder, 0, preOrder.size()-1);
}