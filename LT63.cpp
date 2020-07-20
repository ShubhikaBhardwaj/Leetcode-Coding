//Unique Paths II

class Solution {
public:
    int fun(int x,int y, int a,int b,vector<vector<int>>& obstacleGrid)  //->Time 2^N   N=n*m
    {
        if(x==a&&y==b)
        return 1;

        if(obstacleGrid[x][y]==1)  
        return 0;

        int count=0;
        if(x+1<=a)
        count+=fun(x+1,y,a,b,obstacleGrid);

        if(y+1<=b)
        count+=fun(x,y+1,a,b,obstacleGrid);

        return count;

    }

    int fun1(int x,int y, int a,int b,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp)  //->Time 2N   Space n^2

    {
        if(x==a&&y==b)
        return dp[x][y]=1;

        if(obstacleGrid[x][y]==1)  
        return dp[x][y]=0;

        if(dp[x][y]!=0)
        return dp[x][y];

        int count=0;
        if(x+1<=a)
        count+=fun1(x+1,y,a,b,obstacleGrid,dp);

        if(y+1<=b)
        count+=fun1(x,y+1,a,b,obstacleGrid,dp);

        return dp[x][y]=count;

    }

    
    int fun2(int x,int y, int a,int b,vector<vector<int>>& obstacleGrid,vector<vector<int>> &dp)   //->Time n^2   Space n^2
    {  for(int x=a;x>=0;x--)
       for(int y=b;y>=0;y--)
       {
        if(x==a&&y==b)
          { dp[x][y]=1; continue;}

        if(obstacleGrid[x][y]==1)  
         {dp[x][y]=0;continue;}

        int count=0;
        if(x+1<=a)
        count+=dp[x+1][y];  //fun1(x+1,y,a,b,obstacleGrid,dp);

        if(y+1<=b)
        count+=dp[x][y+1];  //fun1(x,y+1,a,b,obstacleGrid,dp);

         dp[x][y]=count;
       }
       
       return dp[0][0];
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int a=obstacleGrid.size();
        int b=obstacleGrid[0].size();

        vector<vector<int>>dp(a,vector<int>(b,0));
        
        if(obstacleGrid[a-1][b-1]==1||obstacleGrid[0][0]==1)
            return 0;

        //return fun(0,0,a-1,b-1,obstacleGrid);
        //return fun1(0,0,a-1,b-1,obstacleGrid,dp);
         return fun2(0,0,a-1,b-1,obstacleGrid,dp);
      
        
    }
};