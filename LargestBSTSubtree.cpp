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
    class allSol
    {   public:
        int size;
        bool isBST;
        int smallEle;
        int bigEle;
     allSol()
     {
         size=0;
         isBST=true;
        smallEle=-1e8;
        bigEle=1e8;
     }
     
    allSol(int a,bool b,int x,int y)
    {
        size=a;
        isBST=b;
        smallEle=x;
        bigEle=y;
    }

    };


    allSol fun(TreeNode* root,int &maxSize)
    {
        if(root==NULL)
        { return allSol(0,true,-1e8,1e8);
        }
        
        if(root->left==NULL&&root->right==NULL)
        return allSol(1,true,root->val,root->val); 

        allSol p;

        allSol l=root->left?fun(root->left,maxSize):allSol(0,true,-1e8,1e8);
        allSol r=root->right?fun(root->right,maxSize):allSol(0,true,-1e8,1e8);


        if(root->val>l.bigEle&&root->val<=r.smallEle&&l.isBST==true&&r.isBST==true)
           {p.isBST=true;
            p.size=l.size+r.size+1;
            p.bigEle=max(root->val,max(l.bigEle,r.bigEle));
            p.smallEle=min(root->val,min(l.smallEle,r.smallEle));
           }

        else
        {
            p.isBST=false;
            p.size=max(1,max(l.size,r.size));
            p.bigEle=root->val;
            p.smallEle=root->val;
        }
           
       maxSize=max(maxSize,p.size);
       return p;
     
    }

    int largestBSTSubtree(TreeNode* root) {
      if(root==NULL)return 0;
    
      int maxSize=-1e8;
      allSol p=fun(root,maxSize);
    
     return max(maxSize,p.size);
        
    }
};