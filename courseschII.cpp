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

  //  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int N=numCourses;
        graph.resize(N,vector<Edge>());

        for(int i=0;i<prerequisites.size();i++)
        {
            int u=prerequisites[i][0];
            int v=prerequisites[i][1];

            addEdge(v,u);
        }
     
      
        vector<int> inDegree(N,0);

        for(int i=0;i<N;i++)
        {
            for(Edge e:graph[i])
            inDegree[e.v]++;
        }

        queue<int>q;
        vector<int>ans;
        

        for(int i=0;i<N;i++)
        {
            if(inDegree[i]==0)
               q.push(i);
        }

        while(q.size()!=0)
        {
            int rvtx=q.front();
            q.pop();
            
            ans.push_back(rvtx);
            
            for(Edge e: graph[rvtx])
            { if(--inDegree[e.v]==0)
                 q.push(e.v);

            }
        }
        
        if(ans.size()!=N) 
        {
            vector<int> bs;
            return bs;
        }

        else return ans;
    }
};