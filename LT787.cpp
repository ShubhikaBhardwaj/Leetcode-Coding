

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


class DPair
{ public:
    int u;
    int wsf; //weight so far
    int stop;
    
  DPair(int a,int d,int e)
  {
      u=a;
      wsf=d;
      stop=e;
  }
};

struct compareTo
{
    bool operator()(const DPair &a,const DPair &b)const
    {  
       return a.wsf>b.wsf;
    }
};

void display( vector<vector<Edge>> &graph)
{
    for(int i=0;i<graph.size();i++)
    {
        cout<<i<<"->";
        for(Edge e:graph[i])
        {
            cout<<"("<<e.v<<","<<e.w<<") ";
        }
        cout<<endl;
    }

    cout<<endl;
}

int dijkstra(int src,int N,int dest,vector<vector<Edge>> &graph,vector<bool>&vis,int k)
{
  priority_queue<DPair,vector<DPair>,compareTo> pq;
  pq.push(DPair(src,0,k+1));

  while(pq.size()!=0)
  {
      DPair rvtx=pq.top();
      pq.pop();

      if(rvtx.u==dest)// dest found
      return rvtx.wsf;

      if(rvtx.stop==0)  //Useless edge->more than k+1 stops
      continue;

      for(Edge e:graph[rvtx.u])
      {
          if(!vis[e.v])
          {   pq.push(DPair(e.v,rvtx.wsf+e.w,rvtx.stop-1));
           }
      }

  }

  return -1;

}


    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<Edge>> graph(n,vector<Edge>());

    for(int i=0;i<flights.size();i++)
    {
        addEdge(graph,flights[i][0],flights[i][1],flights[i][2]);
    }    
    vector<bool> vis(n,false);  //visited not required bcz undirected graph
    int ans=dijkstra(src,n,dst,graph,vis,K);
    return ans;

    }
};


