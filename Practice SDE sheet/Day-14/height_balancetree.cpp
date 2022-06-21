

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
int height(BinaryTreeNode<int>* root){
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + max(l,r);
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if(root == NULL) return true;
    int l = height(root->left);
    int r = height(root->right);
    if(abs(l-r) > 1)
    {
        return false;
    }
    return isBalancedBT(root->left) && isBalancedBT(root->right);
}