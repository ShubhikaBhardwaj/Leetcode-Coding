
class Solution {
public:

int dfs(int sx,int sy,vector<vector<int>> &mat)
{ if(mat[sx][sy]!=1)
    return 0;
    
    mat[sx][sy]=-1;

    int area=0;
    
    int a=mat.size();
    int b=mat[0].size();
    int dx[]={0,0,1,-1};
    int dy[]={1,-1,0,0};

    for(int k=0;k<4;k++)
    {
        int x=sx+dx[k];
        int y=sy+dy[k];

        if(x>=0&&y>=0&&x<a&&y<b&&mat[x][y]==1)
        area+=dfs(x,y,mat);
    }

    return area+1;
    
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.size()==0||grid[0].size()==0)
        return 0;

        int a=grid.size();
        int b=grid[0].size();

        int maxArea=0;

        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if(grid[i][j]==1)
                {  int area=dfs(i,j,grid);
                   maxArea=max(maxArea,area);
                }
            }
        }

       // cout<<maxArea<<endl;
       return maxArea;
        
    }
};