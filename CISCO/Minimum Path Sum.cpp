//746. Min Cost Climbing Stairs
class Solution {
public:
   int fun(int n,vector<int>& cost,vector<int>& dp)
    {int N=n;
       for(int n=0;n<=N;n++)
       { if(n<=1)
         {dp[n]=cost[n]; continue;}
  
       int mincost=1e8;

       if(n-1>=0)
       mincost=min(mincost,dp[n-1]);

       if(n-2>=0)
       mincost=min(mincost,dp[n-2]);

       if(n==cost.size())
           mincost+=0;
       else
       mincost+=cost[n];

        dp[n]=mincost;
       }
     return dp[N];

   }


    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,0);
        return fun(n,cost,dp);
        
    }
};