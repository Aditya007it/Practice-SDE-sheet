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
int fun(TreeNode<int> *root, int &res){
    if(root == NULL) return 0;
    int l = fun(root->left, res);
    int r = fun(root->right, res);
    int temp = max(l,r)+1;
    int ans = max(temp, (1+r+l));
    res = max(ans,res);
    return temp;
}
int diameterOfBinaryTree(TreeNode<int> *root){

	// Write Your Code Here.
    int res = INT_MIN;
    fun(root, res);
    return res;
}
