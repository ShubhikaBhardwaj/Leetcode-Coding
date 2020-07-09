
class Solution {
public:

    
     int islandPerimeter(vector<vector<int>>& grid) {
  
        int N=grid.size();
        if(N==0)return 0;

        int M=grid[0].size();
        if(M==0)return M;
         
        int count=0;
        int neighbours=0;
        
        for(int i=0;i<N;i++)
        {  for(int j=0;j<M;j++)
            {              
             if(grid[i][j]==1)
               {  
                 count++;
                 int dx[]={0,0,1,-1};
                 int dy[]={1,-1,0,0};
         
                  for(int k=0;k<4;k++)
                    {
                       int rx=i+dx[k];
                       int ry=j+dy[k];

                       if(rx>=0&&ry>=0&&rx<N&&ry<M)
                          if(grid[rx][ry]==1)
                           neighbours++;                         
                  
                    }
               }    
            }   
          
       }
       
        long long ans=(4*count)-(neighbours);
        ans=ans%1000000007;

        return (int)ans;
        
    }

};
    
  