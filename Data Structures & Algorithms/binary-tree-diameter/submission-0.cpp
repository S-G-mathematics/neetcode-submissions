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

public:
    int maxh(TreeNode*root){
        if(root==nullptr)return 0;
        return 1+max(maxh(root->left),maxh(root->right));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        int left=maxh(root->left);
        int right=maxh(root->right);
        int d=left+right;
        int sub=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(d,sub);
    }
};
