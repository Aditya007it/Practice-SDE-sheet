/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
void mirror(BinaryTreeNode<int>* root){
    if(root == NULL) return ;
    mirror(root->left);
    mirror(root->right);
    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
}
bool istrue(BinaryTreeNode<int>* a,BinaryTreeNode<int>* b){
    if(a==NULL && b==NULL) return true;
    if(a==NULL || b==NULL || a->data!=b->data) return false;
    return istrue(a->left, b->left) && istrue(a->right, b->right);
}
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL) return true;
    BinaryTreeNode<int>* p, *q;
    p = root->left;
    q = root->right;
    mirror(p);
    
    return istrue(p,q);
}