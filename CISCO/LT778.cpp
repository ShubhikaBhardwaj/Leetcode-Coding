//778. Swim in Rising Water

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        typedef vector<int> pii; //{ele,i*b+j}
        priority_queue<pii,vector<pii>,greater<pii>> pq;

        int a=grid.size();
        int b=grid[0].size();

        int ans=0;

        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};

        pq.push({grid[0][0],0});
        while(pq.size()!=0)
        {
           pii rm=pq.front();
           pq.pop();

           int x=rm/b;
           int y=rm%b;

           ans=max(ans,grid[x][y]);

           if(x==a-1&&y==b-1)//dest
           return ans;

           if(grid[x][y]==-1) //cycle
           comtinue;

           grid[x][y]=-1; //visited

           for(int k=0;k<4;k++)
           {
               int r=x+dx[k];
               int c=y+dy[k];

               if(r>=0&&c>=0&&r<a&&c<b&&grid[r][c]!=-1)
               {
                   pq.push({grid[r*b+c],r*b+c});
               }

           }

        }

        return ans;
        
    }
};