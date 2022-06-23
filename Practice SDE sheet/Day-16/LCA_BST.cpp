/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* a, TreeNode<int>* b)
{
	// Write your code here
        while(root!=NULL){
            if( (a->data <= root->data && b->data >=  root->data) || (a->data >= root->data && b->data <= root->data) )
            {
                return root;
            }

            else if(a->data > root->data)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
        
    
//     return NULL;
}
