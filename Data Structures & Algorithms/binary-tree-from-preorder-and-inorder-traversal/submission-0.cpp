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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty())return nullptr;
        if(preorder.size()==1)return new TreeNode(preorder[0]);
        TreeNode* root=new TreeNode(preorder[0]);
        int idx=find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        vector<int> inorderleft(inorder.begin(),inorder.begin()+idx);
        vector<int> inorderright(inorder.begin()+idx+1,inorder.end());
        int size=inorderleft.size();
        vector<int> preorderleft(preorder.begin()+1,preorder.begin()+size+1);
        vector<int> preorderright(preorder.begin()+size+1,preorder.end());
        root->left=buildTree(preorderleft,inorderleft);
        root->right=buildTree(preorderright,inorderright);
        return root;
    }
};
