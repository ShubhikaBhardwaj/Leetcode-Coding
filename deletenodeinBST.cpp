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
    //int maxEle=-1e8;
    int maximum(TreeNode* root)
    {
        if(root==NULL)
        return -1e8;

        return max(root->val,max(maximum(root->left),maximum(root->right)));


    }


    TreeNode* deleteNode(TreeNode* root, int key) {
       if(root==NULL)
       return root;

       if(key<root->val)
       root->left=deleteNode(root->left,key);

       else if(key>root->val)
       root->right=deleteNode(root->right,key);

       else if(key==root->val)
       {
           if(root->left==NULL||root->right==NULL)
           {
               TreeNode *rm=root;
               root=(root->left!=NULL)? root->left:root->right;
               return root;
           }
           
           else
           {
               int maxEle=maximum(root->left);

               root->val=maxEle;
               root->left=deleteNode(root->left,maxEle);
               return root;
               
           }
           

       }
       
       return root;
        
    }
};