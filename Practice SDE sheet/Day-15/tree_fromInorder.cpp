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
TreeNode<int> * buildTree(vector<int> &in,int inStart, int inEnd, vector<int> &pre, int preStart, int preEnd){
    if(inStart > inEnd || preStart > preEnd){
        return NULL;
    }
    int rootData = pre[preStart];
    int rootIndex = -1;
    for(int i = inStart; i <= inEnd; i++){
        if(rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int left_inStart = inStart;
    int left_inEnd = rootIndex-1;; 
    int left_preStart = preStart + 1; 
    int left_preEnd = left_inEnd - left_inStart + left_preStart;
    int right_inStart = rootIndex+1;
    int right_inEnd = inEnd;
    int right_preEnd = preEnd;
    int right_preStart = left_preEnd+1;
    
    
    TreeNode<int> * root = new TreeNode<int>(rootData);
    root->left = buildTree(in, left_inStart, left_inEnd, pre, left_preStart, left_preEnd);
    root->right = buildTree(in, right_inStart, right_inEnd, pre, right_preStart, right_preEnd);
    
    return root;
    
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    return buildTree(inorder, 0, inorder.size()-1, preorder, 0, preorder.size()-1);
}