//1219. Path with Maximum Gold
class Solution {
public:
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        int x=grid[i][j];
        grid[i][j]=0;
        
        int gold=0;

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        for(int k=0;k<4;k++)
        {
            int x=i+dx[k];
            int y=j+dy[k];

            if(x>=0&&y>=0&&x<grid.size()&&y<grid[0].size()&&grid[x][y]!=0)
            {
               gold=max(gold,dfs(x,y,grid));
            }
        }
       
       grid[i][j]=x;
        return gold+x;
     
    }


    int getMaximumGold(vector<vector<int>>& grid) {

        int a=grid.size();
        int b=grid[0].size();
        
        int maxCost=-1e8;
        
        vector<vector<int>> mat;
        mat=grid;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {  mat=grid;
                if(mat[i][j]!=0)
               maxCost=max(maxCost,dfs(i,j,mat));
            }
        }

        return maxCost;
        
    }
};