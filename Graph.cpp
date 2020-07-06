//Graph theory

#include<vector>
#include<iostream>

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

vector<vector<Edge>>graph;
int N;

void addEdge(int u,int v,int w)
{
  graph[u].push_back(Edge(v,w));
  graph[v].push_back(Edge(u,w));
}

void constructGraph()
{
    int N=7;
    graph.resize(N,vector<Edge>());
}

void display()
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

int Searchvrtx(int u,int v)
{
    int idx=-1;
    for(int i=0;i<graph[u];i++)
    {
        Edge e=graph[u][i];
        if(e.v==v)
        {
            idx=i;
            break;
        }
    }
    return idx;
}

void removeEdge(int u,int v)
{ int idx=Searchvrtx(u,v);
  graph[u].erase(graph[u].begin()+idx);

  int idx=Searchvrtx(v,u);
  graph[v].erase(graph[v].begin()+idx);

}


void removeVertex(int u)
{ 
    for(int i=0;i<graph[u].size();i++)
    {
        graph[u].erase(graph[u].begin()+i);
    }

}

int main()
{
    constructGraph();
    addEdge(0,1,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    
    addEdge(0,3,10);
    addEdge(3,4,2);
    addEdge(4,5,2);
    
    addEdge(4,6,8);
    addEdge(5,6,3);
    
    //removeVertex(3);
    
    removeEdge(1,2);
    
    display();
    return 0;
}









