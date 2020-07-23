//Unit Area of largest region of 1's
#include<bits/stdc++.h>
using namespace std;

int dfs(int sx,int sy,vector<vector<int>> &mat)
{  if(mat[sx][sy]!=1)
    return 0;
    
    mat[sx][sy]=-1;

    int area=0;
    
    int a=mat.size();
    int b=mat[0].size();
    int dx[]={0,0,1,1,1,-1,-1,-1};
    int dy[]={1,-1,0,1,-1,0,1,-1};

    for(int k=0;k<8;k++)
    {
        int x=sx+dx[k];
        int y=sy+dy[k];

        if(x>=0&&y>=0&&x<a&&y<b&&mat[x][y]==1)
        area+=dfs(x,y,mat);
    }

    return area+1;
    
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
        int x;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cin>>x;
                mat[i][j]=x;
            }
        }
        int maxArea=-1e8;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(mat[i][j]==1)
                {  int area=dfs(i,j,mat);
                   maxArea=max(maxArea,area);
                }
            }
        }

        cout<<maxArea<<endl;
    }
    



	return 0;
}