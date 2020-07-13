class Solution {
public:
   vector<vector<int>>graph;

   void addEdge(int u,int v)
   {
    graph[u].push_back(v); 
   }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

       graph.resize(M*N,vector<int>());
        int N=matrix.size();
        int M=matrix[0].size();

        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<M-1;j++)
            {   int u=matrix[i][j]; 
                int v=matrix[i][j+1];
                 
                if(u<v)
                addEdge(u,v);

                else if(v<u)
                addEdge(v,u);

                v=matrix[i+1][j];

                if(u<v)
                addEdge(u,v);

                else if(v<u)
                addEdge(v,u);
            }
        }

        vector<vector<int>> inDegree(N,(M,vector<int>()));

        for(int i=0;i<N*M;i++)
        {
            for(int e:graph[i])
            inDegree[e.v]++;
        }

        int maxlen=0;
        vector<pair<int,int>>maxPath;

        
        for(int i=0;i<N-1;i++)
        {
            for(int j=0;j<M-1;j++)
             {
            if(inDegree[i]==0)
               { q.push({i,j});
                 
                 queue<int>q;
                 vector<int>ans;
        
                 while(q.size()!=0)
                   {
                        pair<int,int> rvtx=q.front();
                        q.pop();
            
                        ans.push_back(rvtx);

                        int dx[]={0,0,-1,1};
                        int dy[]={1,-1,0,0};
                         
                        for(int k=0;k<4;k++)
                           {  int nx=rvtx.first+dx[k];
                              int ny=rvtx.second+dy[k];
                               
                               if(--inDegree[e.v]==0)
                              q.push(e.v);

                            }         
                    }

                  int len=ans.size();
                  if(len>maxlen)
                  {
                      maxlen=len;
                      maxPath=ans;
                  }
               }
             }
        }

        return maxPath;
        
    }
};