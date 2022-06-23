/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int succ = -1;
    BinaryTreeNode<int>* p = root;
    while(p!=NULL){
        if(p->data <= key){
            p = p->right;
        }
        else{
            succ = p->data;
            p = p->left;
        }
    }
    p = root;
    int pred = -1;
    while(p!=NULL){
        if(p->data < key){
            pred = p->data;
            p = p->right;
        }
        else{
            p = p->left;
        }
    }
    return {pred,succ};
    
}
