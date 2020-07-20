//Kosaraju's Algorithm

#include<iostream>
#include<vector>
 
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

int N;

void addEdge(vector<vector<Edge>>graph,int u,int v,int w)
{
  graph[u].push_back(Edge(v,w));
 
}

void topoSort(int src,vector<vector<Edge>>graph,vector<bool> &vis,stack<int>&s)
{
    vis[src]=true;

    int N=graph.size();
    

}





void kosaraju()
{  
    vector<bool> vis(N,false);
    stack<int> s;
    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        topoSort(i,vis,s);
    }

    reversegraph();

    
    vector<bool> vis1(N,false);
    int c=0;
    while(s.size()!=0)
    {
        int rvtx=s.top();
        s.pop();

        if(!vis1[rvtx])
        dfs(rvtx,bool);
        
        c++;
        cout<<endl;
    }

    cout<<"No of Strongly Connected Components "<<c<<endl;
    
}