#include<bits/stdc++.h>
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
long long int fun(TreeNode<int> *root, long long int &sum){
    if(root == NULL) return 0;
    long long int l = fun(root->left, sum);
    long long int r = fun(root->right, sum);
    int c = max(l,r)+root->val;
    long long int temp = max(c, root->val);
//     long long int ans = max(temp, l+r+root->val);
    sum = max(sum, l+r);
    return temp;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    long long int sum = INT_MIN;
    return fun(root, sum);
}