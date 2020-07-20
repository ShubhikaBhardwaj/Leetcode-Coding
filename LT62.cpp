//Unique Paths
class Solution {
public:
  int fun(int sr,int sc,int er,int ec)
  {  if(sr==er&&sc==ec)
      return 1;

      int count=0;
      
      if(sr+1<=er)
      count+=fun(sr+1,sc,er,ec);

      if(sc+1<=ec)
      count+=fun(sr,sc+1,er,ec);

      return count;
  }

  int fun1(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
  {  if(sr==er&&sc==ec)
      return dp[sr][sc]=1;

      if(dp[sr][sc]!=0)
      return dp[sr][sc];

      int count=0;
      
      if(sr+1<=er)
      count+=fun1(sr+1,sc,er,ec);

      if(sc+1<=ec)
      count+=fun1(sr,sc+1,er,ec);

      return dp[sr][sc]=count;
  }


  int fun2(int sr,int sc,int er,int ec,vector<vector<int>> &dp)
  {  
      for(sr=er;sr>=0;sr--)
      {
      for(sc=ec;sc>=0;sc--)
      {
      if(sr==er&&sc==ec)
        {dp[sr][sc]=1;
         continue;
        }

      int count=0;
      
      if(sr+1<=er)
      count+=dp[sr+1][sc];

      if(sc+1<=ec)
      count+=dp[sr][sc+1];
      
      dp[sr][sc]=count;
      }

      }

     return dp[0][0];
  }

    int uniquePaths(int m, int n) {
         vector<vector<int>>dp(m,vector<int>(n,0));
        //return fun(0,0,m-1,n-1);

        //return fun1(0,0,m-1,n-1,dp);

        return fun2(0,0,m-1,n-1,dp);
    }
};