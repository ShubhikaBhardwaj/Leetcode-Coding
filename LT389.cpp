class Solution {
public:
   int findPar(int u)
{   
    if(par[u]==u)
    return u;

    return par[u]=findPar(par[u]);
}

    int numSimilarGroups(vector<string>& A) {

        vector<int> par;
        int N=A.size();
        int count=N;

        for(int i=0;i<N;i++)
        {
            par.push_back(i);
        }

        for(int i=0;i<N;i++)
        {  
            for(int j=i+1;j<N;j++)
            {  
                int change=0;
               for(int k=0;k<N;k++)
               {
                  if(A[i][k]!=A[j][k])
                  change++;
               }
               
               if(change==0||change==2)
               {
                  int p1=findPar(i);
                  int p2=findPar(j);
                  
                  if(p1!=p2)
                  {
                      par[i]=p1;
                      par[j]=p2;
                      count--;
                  }

               }

            }

        }

        return count;
        
    }
};