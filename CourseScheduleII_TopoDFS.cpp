class Solution {
public:
//course schedule

class Edge
{  public:
    int v;
    
    public:
    Edge(int v)
    {
        this->v=v;
    
    }
};

vector<vector<Edge>>graph;

void addEdge(int u,int v)
{
  graph[u].push_back(Edge(v));
  
}
                                        
bool TopoDFS(int src, vector<bool>&vis, vector<int>& s, vector<bool> &recStack)
{
vis[src]=true;
recStack[src]=true;

bool isCycle=false;
for(Edge e:graph[src])
{
    if(!vis[e.v])
    isCycle=isCycle||TopoDFS(e.v,vis,s,recStack);

    else
    {
       if(recStack[e.v]==true)
        return true;
    }
    
}

s.push_back(src);
recStack[src]=false;

return isCycle;

}
  
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        graph.resize(N,vector<Edge>());

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            addEdge(v,u);
        }
     
        vector<bool>vis(N,false);
        vector<int> s;
        vector<bool>recStack(N,false);
         
        bool res=false; 
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            { res=res||TopoDFS(i,vis,s,recStack); }
        }
        
        if(res==true)//Cycle
          {  vector<int>base;
              return base;

          }
        reverse(s.begin(),s.end());
        return s;

        }
};