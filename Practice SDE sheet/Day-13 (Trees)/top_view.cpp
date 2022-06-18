
// Submitted on Jun 18, 2022, 1:04:36 PM

#include<bits/stdc++.h>
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    map<int,int> mp;
    queue<pair<TreeNode<int> *,int>> q;
    q.push({root, 0});
    while(!q.empty()){
        TreeNode<int> * node = q.front().first;
        int line = q.front().second;
        q.pop();
        if(mp.count(line) == 0){
            mp[line] = node->val;
        }
        if(node->left!=NULL){
            q.push({node->left,line-1});
        }
        if(node->right!=NULL){
            q.push({node->right,line+1});
        }
    }
    
    
    for(auto &it : mp){
        ans.push_back(it.second);
    }
    return ans;
}