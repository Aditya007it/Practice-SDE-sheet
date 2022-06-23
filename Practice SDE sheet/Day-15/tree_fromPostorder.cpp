/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int>* buildTree(vector<int> &in,int inStart, int inEnd, vector<int> &post, int postStart, int postEnd){
    if(inStart > inEnd ){
        return NULL;
    }
    int rootData = post[postEnd];
    int rootIndex = -1;
    for(int i = inStart; i <= inEnd; i++){
        if(rootData == in[i]){
            rootIndex = i;
            break;
        }
    }
    int left_inStart = inStart;
    int left_inEnd = rootIndex-1;; 
    int left_postStart = postStart; 
    
    int right_inStart = rootIndex+1;
    int right_inEnd = inEnd;
    int right_postEnd = postEnd-1;;
    int right_postStart =  right_inStart - right_inEnd + right_postEnd;
    int left_postEnd = right_postStart-1;
    
    TreeNode<int> * root = new TreeNode<int>(rootData);
    root->left = buildTree(in, left_inStart, left_inEnd, post, left_postStart, left_postEnd);
    root->right = buildTree(in, right_inStart, right_inEnd, post, right_postStart, right_postEnd);
    return root;
    
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
    return buildTree(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1);
}
