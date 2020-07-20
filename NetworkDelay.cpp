//Network Delay

class Solution {
public:
   void addEdge(vector<vector<pii>> &graph,int u,int v,int w)
   {
       pii p;
       p.first=v; p.seocnd=w;
       graph[u].push_back(p);
   }

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        int src=K;
        N++;
        typedef pair<int,int> pii;
        vector<vector<pii>> graph(N,vector<pi>());

        for(int i=0;i<times.size();i++)
        addEdge(graph,times[i][0],times[i][1],times[i][2]);

        typedef vector<int> PQPair;

        //{wsf,u}
        priority_queue<PQPair,vector<PQPair>,greater<PQPair>> pq;
        pq.push({0,src});

        vector<int> minDistance(N,1e8);
        minDistance[src]=0;

        while(pq.size()!=0)
        {
            PQPair rm=pq.top();
            pq.pop();

            int wsf=rm[0];
            int u=rm[1];

            for(pii e: graph[u])
            {
                int v=e.first; int w=e.second;
                pq.push({wsf+w,v});
            }
        }
        
        int time=0;

        for(int i=1;i<N;i++)
        {
            if(minDistance[i]==1e8)
            return -1;
            
            else
            time=max(time,minDistance[i]);
        }

        return time;
        
    }
};