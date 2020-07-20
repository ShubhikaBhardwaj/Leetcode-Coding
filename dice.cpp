#include<iostream>
#include<vector>

using namespace std;

int fun(int s,int n)
{
 if(n==s)
 return 1;
   int count=0;
    for(int i=1;i<=6;i++)  //die values
    {
    
        if(s+i<=n)
       count+=fun(s+i,n);
    }
    return count;
}

int fun1(int s,int n,vector<int> &dp)
{
 if(s==n)
 return dp[s]=1;

 if(dp[s]!=0)
 return dp[s];
 
   int count=0;
    for(int i=1;i<=6;i++)  //die values
    { 
        if(s+i<=n)
       count+=fun1(s+i,n,dp);
    }
    return dp[s]=count;
}


int fun2(int s,int n,vector<int> &dp)
{
    
    for(int s=n;s>=0;s--)
    {
       if(s==n)
        {dp[s]=1;
         continue;
        }

 
        int count=0;
    for(int i=1;i<=6;i++)  //die values
    { 
        if(s+i<=n)
       count+=dp[s+i];
    }
    
    
    dp[s]=count;
    }
    
    return dp[0];
    
}

int main()
{   int n=10;
    vector<int>dp(n+1,0);
    cout<<fun(0,n);
    cout<<endl;
    cout<<fun1(0,n,dp);
    cout<<endl;
    
    for(int i=0;i<n+1;i++)
    cout<<dp[i]<<"  ";

    cout<<endl;
    
    
    cout<<fun2(0,n,dp);
    cout<<endl;
    
    for(int i=0;i<n+1;i++)
    cout<<dp[i]<<"  ";
    return 0;
}
