class Solution {
public:
//    class Edge
//    {   public: 
//        int v;
//         Edge(int v)
//        {this->v=v;}
//    };

//     vector<vector<Edge>> g;

//     void addEdge(int u,int v)
//     {
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
   

    bool isBipartite(vector<vector<int>>& graph) {

        int color=0;
        int N=graph.size();
       
        int arr[N];
        for(int i=0;i<N;i++)
           {arr[i]=-1;}
        
        queue<int> q;  //BFS using queue
        q.push(0);

    for(int i=0;i<N;i++)
    {  
       if(arr[i]==-1) 
        while(q.size()!=0)
        {
            int size=q.size();
            while(size-->0)
            {
                int rm=q.front();
                q.pop();
            
                if(arr[rm]==-1)
                {
                arr[rm]=color;
                }

                else if(arr[rm]!=color)
                {  return false;
                }
            
                else 
                arr[rm]=color;
            
            
               for(int e: graph[rm])
               { 
                    if(arr[e]==-1)
                    {
                        q.push(e);
                    }
                }
            }

            
                color=(!color);
        }

        
    }
  return true;
}
};