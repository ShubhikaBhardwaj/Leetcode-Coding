//Graph theory

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

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
    int par;
    int w;
    int wsf; //weight so far
    
  DPair(int a,int b,int c,int d)
  {
      u=a;
      par=b;
      w=c;
      wsf=d;
  }
};

struct compareTo
{
    bool operator()(const DPair &a,const DPair &b)
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

void dijkstra(int src,int N,vector<vector<Edge>> &graph)
{
  priority_queue<DPair,vector<DPair>,compareTo> pq;
  pq.push({src,-1,0,0});

  vector<vector<Edge>> ST(N,vector<Edge>());

  vector<bool> vis(N,false);
  int vertices=N;
  int edges=0;
  while(edges<vertices-1)
  {
      DPair rvtx=pq.top();
      pq.pop();

      if(vis[rvtx.u]) //already visited->cycle
      continue;

      vis[rvtx.u]=true;
      addEdge(ST,rvtx.par,rvtx.u,rvtx.w);
      edges++;

      for(Edge e:graph[rvtx.u])
      {
          if(!vis[e.v])
          {
              pq.push({e.v,rvtx.u,e.w,rvtx.wsf+e.w});
          }
      }

  }

  display(ST);

}


int main()
{
    
    int N=10;
    vector<vector<Edge>>graph;
    graph.resize(N,vector<Edge>());
    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,40);
    
    addEdge(graph,0,3,10);
    addEdge(graph,3,4,2);
    addEdge(graph,4,5,2);
    
    addEdge(graph,4,6,8);
    addEdge(graph,5,6,3);
    cout<<"**********\n";
    display(graph);
    cout<<"@@@@@@@@@@@@@@\n";
    int src=0;
    dijkstra(src,N,graph);

    return 0;
}









