/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
   bool find(TreeNode* node,int data)
   {
       TreeNode* cur=node;
       while(cur!=NULL)
       {
           if(cur->data==data)
           return true;

           else if(cur->data>data)
           cur=cur->left;

           else 
           cur=cur->right;
       }

     return false;

   }



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

      TreeNode* cur=root;

      while(cur!=NULL)
      {
          if(cur->data>p->data&&cur->data>q->data)
          cur=cur->left;

          else if(cur->data<p->data&&cur->data<q->data)
          cur=cur->right;

          else
          {
             return find(cur,p->data)&&find(cur,q->data)? cur:NULL;
          }
          
      }   

      return NULL;
        
    }
};