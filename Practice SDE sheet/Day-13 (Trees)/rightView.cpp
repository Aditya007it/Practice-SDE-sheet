


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

void preorder(TreeNode<int> *node, int level, vector<int> &ans){
    if(node == NULL){
        return ;
    }
    if(ans.size() == level){
        ans.push_back(node->data);
    }
    preorder(node->right, level+1,ans);
    preorder(node->left, level+1,ans);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
    preorder(root,0,ans);
    return ans;
}