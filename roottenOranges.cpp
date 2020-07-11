class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>& grid)
    {
        int level=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(q.size()!=0)
        {
            int size=q.size();
            while(size-->0)
            {
                pair<int,int> rm=q.front();
                q.pop();
                
                int dx[]={0,0,1,-1};
                int dy[]={1,-1,0,0};

                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k];
                    int y=j+dy[k];

                    if(grid[x][y]==1)
                    q.push(x,y,grid);
                }
            }
            level++;

        }

        return level;
    }


    int orangesRotting(vector<vector<int>>& grid) {

        int fresh=0;

        int N=grid.size();
        int M=grid.size();

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]==1)
                fresh++;
            }
        }
        
        if(fresh==0)return 0;

        int time=0;
        int cur=0;

        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
               {
                   if(grid==2)
                     { 
                        cur=bfs(i,j,grid);
                        time=max(time,cur); 
                      
                     }

               }
        } 

        return time;

    }
};