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
     int pathsum=0;

    // bool hasPathSum(TreeNode* root, int sum) {

    //   if(root==NULL)
    //   return false;
      
    //   pathsum+=root->val;

    //   if(root->left==NULL&&root->right==NULL)
    //   {
    //       if(pathsum==sum)
    //       return true;

    //       else
    //       {pathsum-=root->val;
    //        return false;
    //       }
          
    //   }

    //   bool ans= hasPathSum(root->left,sum)||hasPathSum(root->right,sum);
    //   if(ans==true) return true;
   
    //   pathsum-=root->val;
        
    // }
    
    vector<vector<int>> pathSumhelper(TreeNode* root, int sum, vector<int> curpath,int cursum)
    {  
      if(root==NULL)
       {
         vector<vector<int>> ans;
         if(cursum==sum)
         ans.push_back(curpath);

         return ans;
       }
     vector<vector<int>> ans;
     
     curpath.push_back(root->val);
     cursum+=root->val;

      if(root->left==NULL&&root->right==NULL)
      {
          if(cursum==sum)
          {
            ans.push_back(curpath);
            
          }

          else
          {
            curpath.pop_back();
            cursum-=root->val;
          }

          return ans;
          
      }

      vector<vector<int>>lp=PathSumhelper(root->left,sum,curpath,cursum);
      vector<vector<int>>rp=PathSumhelper(root->right,sum,curpath,cursum);

      curpath.pop_back();
      cursum-=root->val;
      
      return ans;

    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        vector<int> curans;
        return pathSumhelper(root,sum,curans,0);

    }
};