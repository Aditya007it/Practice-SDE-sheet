/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int>* fun(vector<int> &arr, int l, int h){
    int low = l;
    int high = h;
    if(low > high){
        return NULL;
    }
    int mid = low + (high-low)/2;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = fun(arr,low,mid-1);
    root->right = fun(arr,mid+1,high);
    return root;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    int low = 0;
    int high = n-1;
    return fun(arr,low,high);
    
}