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
    int maxsum=-1e8;
    int fun(TreeNode* node)
    {
        if(node==NULL)
        return -1e8;

        if(node->left==NULL&&node->right==NULL)// laef node
          return node->data;

        int lpathSum=fun(node->left);
        int rpathSum=fun(node->right);

        //always
        maxsum=max(maxsum,max(max(lpathSum,rpathSum),lpathSum+rpathSum+node->val)); 

        return max(lpathSum,rpathSum)+node->val;
        
    }



    int maxPathSum(TreeNode* root) {

        int x=fun(root);
        return maxsum;
    }
};