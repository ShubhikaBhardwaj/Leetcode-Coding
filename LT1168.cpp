
class Solution {
public:

vector<int>par;
int findPar(int u)
{
    if(par[u]==u)
    return u;
    return par[u]=findPar(par[u]);
}


long long minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
       
       for(int i=0;i<wells.size();i++)
       {
           pipes.push_back({0,i+1,wells[i]});
       }

       vector<int>par;

       for(int i=0;i<=n;i++)
       par.push_back(i);

       int cost=0;
    
       
    sort(pipes.begin(),pipes.end(), [](vector<int> &a, vector<int> &b) {
        return a[2] < b[2];
    });

       for(vector<int> &p:pipes)
       { 
          // vector<int>p=pipes[i];
           
               int p1=findPar(p[0]);
               int p2=findPar(p[1]);

               if(p1!=p2)
               {
                   par[p1]=p2;
                   cost+=p[2];
               }
           
       }

       return cost;

    }
};