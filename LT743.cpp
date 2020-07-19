//Network Delay Time
class Solution {
public:

class Edge
{  public:
    int v;
    int w;
    public:
    Edge(int v,int w)
    {
        this->v=v;
        this->w=w;
    }
};


void addEdge(vector<vector<Edge>> &graph,int u,int v,int w)
{
  graph[u].push_back(Edge(v,w));
}


    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int time=0;
        int src=K;
        N=N+1;
        vector<vector<Edge>> graph;
        graph.resize(N,vector<Edge>());
        
        vector<bool> vis(N,false);
        
        for(int i=0;i<times.size();i++)
        addEdge(graph,times[i][0],times[i][1],times[i][2]);

        typedef vector<int> pqPair; //{wsf,u}
        vector<int> minDist(N,1e8);
        priority_queue<pqPair,vector<pqPair>,greater<pqPair>> pq;
        vis[src]=true;
        pq.push({0,src});
        minDist[src]=0;

        while(pq.size()!=0)
        {
            pqPair rvtx=pq.top();
            pq.pop();
            
            int u=rvtx[1];
            int wsf=rvtx[0];
                        
            for(Edge e: graph[u])
            {//  cout<<wsf+e.w<<endl;
                if((wsf+e.w<minDist[e.v]))
                { pq.push({wsf+e.w,e.v});
                 minDist[e.v]=wsf+e.w;
                 
                 
                }

            }
        }
   
       for(int i=1;i<N;i++)
       { //cout<<minDist[i]<<" ";
          if(minDist[i]==1e8)
              return -1;
           
         else if(minDist[i]>time)
         time=minDist[i];
       }
        cout<<endl;
     return time;

    }
};