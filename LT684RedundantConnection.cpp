//Redundant Connection

class Solution {
public:


class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N;
vector<vector<Edge>> graph;

void addEdge(int u, int v, int w)
{
    graph[u].push_back(Edge(v, w));
}


vector<int> par;
vector<int> size;

int findPar(int u)
{   int i=u;
    while(par[i]!=i)
    {
        i=par[i];
    }

    par[u]=i;
    return u;
}

void merge(int a,int b)
{
    if(size[a]>=size[b])
    { par[b]=a;
      size[a]+=size[b];
    }

    else
    { par[a]=b;
      size[b]+=size[a];
    }
    
}


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    graph.resize(n, vector<Edge>());
    for (int i = 0; i < n; i++)
    {
        par.push_back(i);
        size.push_back(1);
    }
   vector<int> res;
    for (vector<int> &e : edges)
    {
        int u = e[0];
        int v = e[1];
        
        int p1 = findPar(u);
        int p2 = findPar(v);

        if (p1 != p2)
        {
            merge(p1, p2);
            addEdge(u, v, w);
        }

        else
        {
           res.push_back(u);
           res.push_back(v);
           break;
        }
        
    }

    return res;
    }
};