class Solution {
public:
   class pos
   {  public:
       int x,y;

       pos(int a,int b)  //constructor ->REMEMBER!!
       {
           x=a;
           y=b;
       }

   };


   void GCC(pos src,vector<vector<char>>& grid)
   {
       grid[src.x][src.y]='0';
       int N=grid.size();
          
       int dx[]={0,0,1,-1};
       int dy[]={1,-1,0,0};

       for(int k=0;k<4;k++)
       {
           pos cur(src.x+dx[k],src.y+dy[k]);
           
          if(cur.x<0||cur.y<0||cur.x>=grid.size()||cur.y>=grid[0].size())
              continue;
              
           else
           {   
              if(grid[cur.x][cur.y]=='1')
              GCC(cur,grid);
           }   
          
       }

   }
    
    int numIslands(vector<vector<char>>& grid) {

        int N=grid.size();
        if(N==0)return 0;

        int count=0;
        //vector<vector<bool>> vis(N,vector<bool>(N,false));
        for(int i=0;i<N;i++)
        {  
            for(int j=0;j<grid[i].size();j++)
            { pos p(i,j);
             
             if(grid[p.x][p.y]=='1')
             { count++;
               GCC(p,grid);
             }
            }
        }

        return count;
        
    }
};