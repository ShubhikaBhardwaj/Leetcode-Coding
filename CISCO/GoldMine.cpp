#include <iostream>
#include<utility>
#include<vector>
using namespace std;

int path(int sx,int sy,vector<vector<int>> &mat)
{ int a=mat.size();
  int b=mat[0].size();

    if(sy==b)
    return mat[sx][sy];

    int dx[]={-1,0,1};
    int maxCost=0;
    for(int k=0;k<3;k++)
    {
        int x=sx+dx[k];
        if(x>=0&&x<a)
        {
            int cost=path(x,sy+1,mat);
            maxCost=max(maxCost,cost);
        }
    }
    
   return maxCost+mat[sx][sy]; 
}


int path1(int sx,int sy,vector<vector<int>> &mat,vector<vector<int>> &dp)
{ int a=mat.size();
  int b=mat[0].size();

    if(sy==b)
    return dp[sx][sy]=mat[sx][sy];

    if(dp[sx][sy]!=0)
    return dp[sx][sy];

    int dx[]={-1,0,1};
    int maxCost=0;
    for(int k=0;k<3;k++)
    {
        int x=sx+dx[k];
        if(x>=0&&x<a&&sy+1>=0&&sy+1<b)
        {
            int cost=path1(x,sy+1,mat,dp);
            maxCost=max(maxCost,cost);
        }
    }
    
   return dp[sx][sy]=maxCost+mat[sx][sy]; 
}


int path2(int sx,int sy,vector<vector<int>> &mat,vector<vector<int>> &dp)
{ for(int i=0)
    
  int a=mat.size();
  int b=mat[0].size();

    if(sy==b)
    return dp[sx][sy]=mat[sx][sy];

    if(dp[sx][sy]!=0)
    return dp[sx][sy];

    int dx[]={-1,0,1};
    int maxCost=0;
    for(int k=0;k<3;k++)
    {
        int x=sx+dx[k];
        if(x>=0&&x<a&&sy+1>=0&&sy+1<b)
        {
            int cost=path1(x,sy+1,mat,dp);
            maxCost=max(maxCost,cost);
        }
    }
    
   return dp[sx][sy]=maxCost+mat[sx][sy]; 
}



int main() {
	int t;
    cin>>t;
    while (t--)
    {
        int a;
        int b;
        cin>>a>>b;

        vector<vector<int>> mat(a,vector<int>(b,0));
        
        vector<vector<int>> dp(a,vector<int>(b,0));
        int x;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cin>>x;
                mat[i][j]=x;
            }
        }
        int maxArea=0;
        for(int i=0;i<a;i++)
        {
             int area=path1(i,0,mat,dp);
             maxArea=max(maxArea,area);
            
        }

        cout<<maxArea<<endl;
    }
    



	return 0;
}