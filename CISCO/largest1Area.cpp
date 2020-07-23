#include<bits/stdc++.h>

using namespace std;

vector<int> par;
vector<int> size;

int findpar(int u)
{
    if(u==par[u])
    return u;

    return par[u]=findpar(par[u]);
}

void merge(int p1,int p2)
{
    if(size[p1]>size[p2])
    {
        size[p1]+=size[p2];
        par[p2]=p1;
    }
    else
    {
        size[p2]+=size[p1];
        par[p1]=p2;
        
    }
    
}

int main() {
int t;
    cin>>t;
    while (t--)
    {
        int a;
        int b;
        cin>>a>>b;

        vector<vector<int>> mat(a,vector<int>(b,0));
        int x;
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                cin>>x;
                mat[i][j]=x;
            }
        }
        
   for(int i=0;i<a;i++)
   {
       for(int j=0;j<b;j++)
       {
      par.push_back((i*b)+j);
      size.push_back(1);
       }
   }

   int dx[]={1,1,1,-1,-1,-1,0,0};
   int dy[]={1,0,-1,1,0,-1,1,-1};

   for(int i=0;i<a*b;i++)
   { 
       int r=i/b;
       int c=i%b;
        if(mat[r][c]==1)
        {   for(int k=0;k<8;k++)
           {
               int x=r+dx[k];
               int y=c+dy[k];
                 
               if(x>=0&&y>=0&&x<a&&y<b)
                  if(mat[x][y]==1)
               { 
                  int p1=findpar(i);             
                  int p2=findpar((x*b)+y);
                  if(p1!=p2)
                  {    merge(p1,p2);
                  }

               }
           }
        }
       
    }

   int ans=0;
   for(int i=0;i<a*b;i++)
   { 
      ans=max(ans,size[i]);
   }

        cout<<ans<<endl;

    }




	return 0;
}