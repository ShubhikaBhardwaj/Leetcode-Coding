#include <bits/stdc++.h>
using namespace std;

class Edge
{ public:
    int v;
    Edge(int v)
    {
        this->v=v;
    }

};

vector<vector<Edge>> graph;

void addEdge(int v,int u)
{
    graph[v].push_back(u);
    graph[u].push_back(v);
    
}

int ConnectedComp(int x,vector<bool>&vis)
{
    
   vis[x]=true;
   int c=0;

   for(Edge e:graph[x])
   {
       if(!vis[e.v])
       {
           c=ConnectedComp(e.v,vis);
       }


   }

   return c+1;

}


vector<string> split_string(string);

int journeyToMoon(int n, vector<vector<int>> astronaut) {
    graph.resize(n,vector<Edge>());

    for(int i=0;i<astronaut.size();i++)
    {
        addEdge(astronaut[i][0],astronaut[i][1]);
    }

   vector<int>cc;
   vector<bool>vis(n,false);
    for(int i=0;i<n;i++)
    {
           int x=ConnectedComp(i,vis);
           cc.push_back(x);
        
    }
    
    int sum=0;

    for(int i=0;i<cc.size();i++)
    {
        for(int j=i+1;j<cc.size();j++)
        {
            sum+=(i*j);
        }
    }

    return sum;


}