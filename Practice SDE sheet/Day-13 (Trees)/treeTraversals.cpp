/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void preorder(BinaryTreeNode<int> *root, vector<int> &pre){
    if(root==NULL){
        return;
    }
    pre.push_back(root->data);
    preorder(root->left,pre);
    preorder(root->right,pre);
}
void postoder(BinaryTreeNode<int> *root, vector<int> &post){
    if(root==NULL){
        return;
    }
    
    postoder(root->left,post);
    postoder(root->right,post);
    post.push_back(root->data);
}
void inorder(BinaryTreeNode<int> *root, vector<int> &in){
    if(root==NULL){
        return;
    }
    
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>>  ans;
    vector<int> pre, post, in;
    inorder(root,in);
    preorder(root,pre);
    postoder(root,post);
    ans.push_back(in);
    ans.push_back(pre);
    ans.push_back(post);
    return ans;
}