

//  Submitted on Jun 18, 2022, 11:44:31 AM

/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    
    while(!q.empty()){
        BinaryTreeNode<int> * p = q.front();
        q.pop();
        ans.push_back(p->val);
        if(p->left!=NULL){
            q.push(p->left);
        }
        if(p->right!=NULL){
            q.push(p->right);
        }
    }
    return ans;
}