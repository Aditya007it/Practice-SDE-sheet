/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void inorder(BinaryTreeNode<int> *root, vector<int> &ds){
    if(root == NULL) return;
    inorder(root->left,ds);
    ds.push_back(root->data);
    inorder(root->right,ds);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    vector<int> ds;
    inorder(root,ds);
    int i = 0, j = ds.size()-1;
    while(i < j){
        if(ds[i] + ds[j] == k){
            return true;
        }
        else if(ds[i]+ds[j] > k){
            j--;
        }
        else{i++;}
    }
    return false;
}