//Cheapest Flights Within K Stops
class Solution {
public:
  typedef pair<int,int> pii;
   void addEdge(vector<vector<pii>>graph,int u, int v,int w)
   {  pii p;
      p.first=u;
      p.second=v;
      graph[u].push_back(pii);
   }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {

        vector<vector<pii>>graph(n,vector<pii>());

        for(int i=0;i<flights.size();i++)
        {
            addEdge(graph,flights[i][0],flights[i][1],flights[i][2]);
        }

        //{wsf,u,k}
        typedef vector<int> PQPair;
        priority_queue<PQPair,vector<PQPair>,greater<int>>pq;

        pq.push({0,src,K});
        vector<int> minDist(N,1e8);

        while(pq.size()!=0)
        {
            PQPair rvtx=pq.top();
            pq.pop();

            int wsf=rvtx[0];
            int u=rvtx[1];
            int stop=rvtx[2];
            
            if(u==dest)
            return minDist[u];

            if(stop==0)
            continue;

            for(pii p:graph[u])
            {
                int v=p.first;
                int w=p.second;
                if(wsf+w<minDist[v])
                {
                    minDis[v]=wsf+w;
                    pq.push({wsf+w,v,stop-1});
                }
            }


        }

         return -1;
        
    }
};