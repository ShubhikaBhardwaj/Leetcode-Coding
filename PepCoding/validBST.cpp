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
    bool fun(TreeNode* node,int min,int max)
    {
        if(root==NULL)return true;

        if(node->val>max||node->val<min)
        return false;

        return fun(node->left,min,node->val)&& fun(node->right,node->val,max);        
    }


    bool isValidBST(TreeNode* root) {

        if(root==NULL)return true;

        return fun(root,-1e8,1e8);    
        
    }
};