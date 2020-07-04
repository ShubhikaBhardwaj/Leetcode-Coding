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
    //hasPathSum=0/1, Sum   
    //check at leaf node only
    vector<int> PathSum(TreeNode *root,int sum)
    {
        if(root==NULL)
        {
            return{0,0};
        }

        if(root->left==NULL&&root->right==NULL) //leaf
        {
            

        }

        int cursum=root->data;

        vector<int> la=PathSum(root->left);

        if(sum==la[1]+cursum)
        {
            return {1,sum}
        }

        vector<int> ra=PathSum(root->right);

        if(sum==la[1]+cursum)
        {
            return {1,sum}
        }

        


        
    }

    bool hasPathSum(TreeNode* root, int sum) {
        
    }
};