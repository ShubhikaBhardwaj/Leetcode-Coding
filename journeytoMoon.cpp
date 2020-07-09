#include <bits/stdc++.h>
using namespace std;

int ConnectedComp(int x,vector<vector<int>>& astronaut,vector<bool>&vis)
{
   vis[x]=true;
   int c=0;

   for(int i=0;i<astronaut.size();i++)
   {  
       if(astronaut[i][0]==x)
       {
           int n=astronaut[i][1];
           if(!vis[n])
           c=ConnectedComp(n,astronaut,vis);
       }

       if(astronaut[i][1]==x)
       {
           int n=astronaut[i][0];
           if(!vis[n])
           c=ConnectedComp(n,astronaut,vis);
       }

   }

   return c+1;

}




vector<string> split_string(string);
//vis->-1
// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronaut) {
   vector<int>cc;
   vector<bool>vis(n,false);
    for(int i=0;i<n;i++)
    {
           int x=ConnectedComp(i,astronaut,vis);
           cc.push_back(x);
        
    }
    
    int sum=0;

    for(int i=0;i<cc.size();i++)
    {
        for(int j=0;j<cc.size();j++)
        {
            sum+=(i*j);
        }
    }

    return sum;


}