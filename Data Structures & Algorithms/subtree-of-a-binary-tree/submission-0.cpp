/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr)return true;
        if(p==nullptr && q!=nullptr)return false;
        if(p!=nullptr && q==nullptr)return false;
        // if(p->left==nullptr && p->right==nullptr && q->left==nullptr && q->right==nullptr && p->val==q->val) return true;
        bool a=(p->val==q->val);
        return a && isSameTree(p->right,q->right) && isSameTree(p->left,q->left);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subroot) {
        if(subroot==nullptr & root==nullptr)return true;
        if(subroot==nullptr && root!=nullptr)return false;
        if(subroot!=nullptr && root==nullptr)return false;
        bool a=isSameTree(root,subroot) || isSameTree(root->left,subroot) ||isSameTree(root->right,subroot);
        return(a||isSubtree(root->left,subroot)||isSubtree(root->right,subroot));
    }


};
