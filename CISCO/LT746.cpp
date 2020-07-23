class Solution {
public:
   int noOfPaths(int s,vector<int>& cost,int n)
   {
       if(s==n)
       return cost[s];

       int path=1e8;
       if(s+1<=n)
       path=min(path,noOfPaths(s+1,cost,n));

       if(s+2<=n)       
       path=min(path,noOfPaths(s+2,cost,n));

       return path+cost[s];
    
   }

   int noOfPaths1(int s,vector<int>& cost,int n,vector<int> &dp)
   {
       if(s==n)
       return dp[s]=cost[s];

       if(dp[s]!=0)
       return dp[s];

       int path=1e8;
       if(s+1<=n)
       path=min(path,noOfPaths1(s+1,cost,n,dp));

       if(s+2<=n)       
       path=min(path,noOfPaths1(s+2,cost,n,dp));

       return dp[s]=path+cost[s];
    
   }


   int noOfPaths2(int s,vector<int>& cost,int n,vector<int> &dp)
   {   for(int s=n;s>=0;s--)
       {
      
       if(s==n)
        {dp[s]=cost[s];continue;}


       int path=1e8;
       if(s+1<=n)
       path=min(path,dp[s+1]);

       if(s+2<=n)       
       path=min(path,dp[s+2]);

        dp[s]=path+cost[s];
       }
       return dp[0];
   }

    int minCostClimbingStairs(vector<int>& cost) {
        
        vector<int> dp(n+1,0);
          return noOfPaths(0,cost,n);
        return noOfPaths1(0,cost,n,dp);
        
        return noOfPaths2(0,cost,n,dp);
    }
};