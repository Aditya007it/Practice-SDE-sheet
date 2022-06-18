

// Submitted on Jun 18, 2022, 1:13:45 PM


/*************************************************************
 
    Following is the Binary Tree node structure.

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

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    map<int,int> mp;
    queue<pair<BinaryTreeNode<int> * , int>> q;
    q.push({root,0});
    while(!q.empty()){
        BinaryTreeNode<int> * node = q.front().first;
        int line = q.front().second;
        q.pop();
        mp[line] = node->data;
        if(node->left!=NULL){
            q.push({node->left, line-1});
        }
        if(node->right!=NULL){
            q.push({node->right, line+1});
        }
    }
    for(auto &it:mp){
        ans.push_back(it.second);
    }
    return ans;
    
}
