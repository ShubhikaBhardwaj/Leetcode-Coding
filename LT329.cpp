//Longest Increasing Path in a Matrix
//Longest Increasing Path in a Matrix

class Solution {
public:

    int longestIncreasingPath(vector<vector<int>>& matrix) {
    int N=matrix.size();
        if(N==0) return 0;
    int M=matrix[0].size();
        if(M==0) return 0;
        // graph.resize(M*N,vector<Edge>());

        // for(int i=0;i<prerequisites.size();i++)
        // {
        //     int u=prerequisites[i][0];
        //     int v=prerequisites[i][1];

        //     addEdge(v,u);
        // }

        vector<vector<int>>Indeg(N,vector<int>(M,0));

        for(int i=0;i<N;i++)
        {  
           for(int j=0;j<M;j++) 
           {
            // for(Edge e:graph[i])
            // {
            //     Indeg[e.v]++;
            // }
             
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};

            for(int k=0;k<4;k++)
            { int x=i+dx[k];
              int y=j+dy[k];
              
              if(x>=0&&y>=0&&x<N&&y<M)
              if(matrix[x][y]>matrix[i][j])
              {
                  Indeg[x][y]++;
              }

            }
           }
        }
        
        queue<pair<int,int>>q;
        

        for(int i=0;i<N;i++)
        { for(int j=0;j<M;j++)
           {
            if(Indeg[i][j]==0)
            q.push({i,j});
           }
        }
        
        int level=0;
        while(q.size()!=0)
        {
            int s=q.size();
            while(s-->0)
            {
            pair<int,int> rm=q.front();
            q.pop();

            // for(Edge e:graph[rm])
            //    {
            //      Indeg[e.v]--;

            //      if(Indeg[e.v]==0)
            //       q.push(e.v);
            //    }
            
            int dx[]={0,0,1,-1};
            int dy[]={1,-1,0,0};
            int i=rm.first;
            int j=rm.second;
            for(int k=0;k<4;k++)
            { int x=i+dx[k];
              int y=j+dy[k];
             
             
              if(x>=0&&y>=0&&x<N&&y<M)
              if(matrix[x][y]>matrix[i][j])
              {
                  Indeg[x][y]--;

                  if(Indeg[x][y]==0)
                  q.push({x,y});
              }

            }
            }

            level++;
        }

        int ans=level;
        return ans;
    }
};