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
TreeNode<int> * fun(TreeNode<int> *root, int x, int y){
    if(root == NULL){
        return NULL;
    }
    if(root->data == x || root->data == y){
        return root;
    }
    TreeNode<int> * l = fun(root->left,x,y);
    TreeNode<int> * r = fun(root->right,x,y);
    if(l!=NULL && r!=NULL){
        return root;
    }
    else{
        if(l == NULL) return r;
        else return l;
    }
}
int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    TreeNode<int> * ans = fun(root, x, y);
    return ans->data;
    
}