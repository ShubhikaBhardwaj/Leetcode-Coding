//Graph theory
//Dijkstra -> single src min weight path to all vertices
//Concept-> BFS+Priority Queue

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


class DPair //Dijkstra Pair
{ public:
    int u;
    int w;
    int wsf; //weight so far
    
  DPair(int a,int c,int d)
  {
      u=a;
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
    vector<int>dist(N,1e8); //min Distance
    dist[src]=0;

    priority_queue<DPair,vector<DPair>,compareTo> pq;
    pq.push(DPair(src,0,0));

    while(pq.size()!=0)
    {
        DPair rm=pq.top();
        pq.pop();

        for(Edge e:graph[u])
        {
            if(rm.wsf+e.w<dist[e.v])
            {
                dist[e.v]=rm.wsf+e.w;
                pq.push(DPair(e.v,e.w,rm.wsf+e.w));
            }
        }
    }

    for(int i=0;i<N;i++)
    cout<<dist[i]<<" ";

    cout<<endl;

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









