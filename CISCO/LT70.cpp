//Climbing Stairs

class Solution {
public:         
   int noOfPaths(int s,int n)
   {
       if(s==n)
       return 1;

       int path=0;
       if(s+1<=n)
       path+=noOfPaths(s+1,n);

       if(s+2<=n)
       path+=noOfPaths(s+2,n);

       return path;
    
   }

      int noOfPaths1(int s,int n,vector<int> &dp)
   {
       if(s==n)
       return dp[s]=1;

       if(dp[s]!=0)
       return dp[s];

       int path=0;
       if(s+1<=n)
       path+=noOfPaths1(s+1,n,dp);

       if(s+2<=n)
       path+=noOfPaths1(s+2,n,dp);

       return dp[s]=path;
    
   }

     int noOfPaths2(int s,int n,vector<int> &dp)
   {
       for(int s=n;s>=0;s--)
       {
       if(s==n)
       { dp[s]=1; continue;}


       int path=0;
       if(s+1<=n)
       path+=dp[s+1];

       if(s+2<=n)
       path+=dp[s+2];

       dp[s]=path;
       }
       return dp[0];
   }




    int climbStairs(int n) {
        vector<int> dp(n+1,0);
          return noOfPaths(0,n);
        return noOfPaths1(0,n,dp);
        
        return noOfPaths2(0,n,dp);
    }
};