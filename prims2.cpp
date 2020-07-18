//prim's
#include<iostream>
#include<vector>
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

void display(vector<vector<Edge>>&graph)
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
}


void addEdge(vector<vector<Edge>>&graph,int u,int v,int w)
{
  graph[u].push_back(Edge(v,w));
}

class PrimsPair
{ public:
    int u;
    int par;
    int w;

   PrimsPair(int a,int b,int c)
   {
       u=a;
       par=b;
       w=c;
   }
};

class CompareTo
{public:
bool operator()(const PrimsPair &A,const PrimsPair &B)const
{
    return A.w>B.w;
}
};

void PrimsAlgo(int src, vector<bool>&vis, vector<vector<Edge>>&graph,int N)
{
   priority_queue<PrimsPair,vector<PrimsPair>,CompareTo> q;

   q.push({src,-1,0});

   vector<vector<Edge>> mst(N,vector<Edge>());
   int edges=0;
   int vertices=N;
   while(edges<=N-1)
   {
      int size=q.size();
      while(size--)
      {
          PrimsPair p=q.top();
          q.pop();

          if(vis[p.u])//cycle
          continue;

          if(p.par!=-1)
          {
              addEdge(mst,p.u, p.par, p.w);
              edges++;
          }

          vis[p.u]=true;
          for(Edge e: graph[p.u])
          {
              if(!vis[e.v])
              q.push({e.v,p.u,e.w});
          }

      }
   }


  display(mst);

}

int main()
{   
    vector<vector<Edge>> graph;
    int N=7;
    graph.resize(N,vector<Edge>());
    addEdge( graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,40);
    
    addEdge(graph,0,3,10);
    addEdge(graph,3,4,2);
    addEdge(graph,4,5,2);
    
    addEdge(graph,4,6,8);
    addEdge(graph,5,6,3);
    
    
    display(graph);
    vector<bool> vis(N,false);
    PrimsAlgo(0,vis,graph,N);

    return 0;
}


