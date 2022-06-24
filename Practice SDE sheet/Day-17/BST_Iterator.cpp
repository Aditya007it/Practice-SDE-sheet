#include<bits/stdc++.h>
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

class BSTiterator
{
    public:
    stack<TreeNode<int> *>st;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        while(root!=NULL){
            st.push(root);
            root = root->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int> * temp = st.top();
        int ans = temp->data;
        st.pop();
        temp = temp->right;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        }
        return ans;
    }

    bool hasNext()
    {
        // write your code here
        if(st.empty()) return false;
        return true;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/