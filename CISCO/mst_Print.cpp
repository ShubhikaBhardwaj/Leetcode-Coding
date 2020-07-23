
// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
vector<int>par;
vector<int>size;

int findPar(int u)
{
    if(par[u]==u)
    return u;

    return par[u]=findPar(par[u]);
}

void merge(int p1,int p2)
{
    if(size[p1]>size[p2])
    { size[p1]+=size[p2];
      par[p2]=p1;
    }

    else
    { size[p2]+=size[p1];
      par[p1]=p2;
    }
    
}

int spanningTree(int V, int E, vector<vector<int>> &graph) {
  int cost=0;

  vector<vector<int>> g(V,vector<int>());
  for(int i=0;i<graph.size();i++)
  {
      for(int j=0;j<graph[i].size();j++)
      {
         int u=i;
         int v=j;
         int w=graph[i][j];
         g[u].push_back(v);
         g[u].push_back(w);
      }
  }

    
    for(int i=0;i<=V;i++)
       {par.push_back(i);
        size.push_back(1);
       }
    
    for(int i=0;i<graph.size();i++)
    {
        for(int j=i+1;j<graph.size();j++)
        {
            
            
                int u=i;
                int v=j;
                int p1=findPar(u);
                int p2=findPar(v);

                if(p1!=p2)
                {
                    merge(p1,p2);
                    cost+=graph[i][j];
                }
        

        }
    }
    par.clear();
    
   return cost;

}