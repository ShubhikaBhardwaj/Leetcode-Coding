class Solution {
public:
   int findPar(int u)
{   
    if(par[u]==u)
    return u;

    return par[u]=findPar(par[u]);
}

//comparator for sorting the graph

    void kruskal(vector<vector<Edge>> &graph, int vertices,vector<vector<Edge>>&MST) {

        vector<int> par;
        int N=vertices; //no of vertices;
        
        for(int i=0;i<N;i++)
        {
            par.push_back(i);
        }

        for(int i=0;i<graph.size();i++)
        {
           for(Edge e: graph[i])
           {
               int u=e.u;
               int v=e.v;
               int p1=findPar(u);
               int p2=findPar(v);

               if(p1!=p2)
               {
                   par[p1]=par[p2]=min(p1,p2); //merge
                   addEdge(MST,u,v,e.w);
               }
           }
        }
    }
};