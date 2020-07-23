//746. Min Cost Climbing Stairs
class Solution {
public:
   int fun(int n,vector<int>& cost)
    {
         if(n<=1)
            return cost[n];
  
       int mincost=1e8;

       if(n-1>=0)
       mincost=min(mincost,fun(n-1,cost));

       if(n-2>=0)
       mincost=min(mincost,fun(n-2,cost));

       mincost+=cost[n];

       return mincost;

   }


    int minCostClimbingStairs(vector<int>& cost) {

        cost.push_back(0);

        return fun(cost.size(),cost);
        
    }
};