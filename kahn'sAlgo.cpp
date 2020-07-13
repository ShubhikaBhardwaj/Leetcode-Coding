class Solution {
public:
    class Edge
    {  public:
        int v;
        Edge(int v)
        {
            this->v=v;
        }

    };

    vector<vector<Edge>> graph;

    void addEdge(int u,int v)
    {
       graph[u].push_back(v);
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

        vector<int>Indeg(N,0);

        for(int i=0;i<N;i++)
        {
            for(Edge e:graph[i])
            {
                Indeg[e.v]++;
            }
        }
        
        queue<int>q;
        vector<int> ans;

        for(int i=0;i<N;i++)
        {
            if(Indeg[i]==0)
            q.push(i);
        }

        while(q.size()!=0)
        {
            int rm=q.front();
            q.pop();

            ans.push_back(rm);

            for(Edge e:graph[rm])
            {
                Indeg[e.v]--;

                if(Indeg[e.v]==0)
                 q.push(e.v);
            }
        }

        if(ans.size()!=N)
        {
            vector<int>bs;
            return bs;
        }

        return ans;
    }
};