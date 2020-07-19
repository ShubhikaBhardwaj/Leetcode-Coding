//Count All Palindrome Sub-Strings in a String
#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

int fun(string s)
{
   int n=s.length();
   bool dp[n][n];
   int count[n][n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {dp[i][j]=false;
        count[i][j]=0;
       }
       
   }
   

   for(int i=0;i<n;i++)
       {dp[i][i]=true;
        count[i][i]=1;
       }

   for(int gap=1;gap<n;gap++)
   {
       for(int i=0,j=i+gap;i+gap<n;i++,j++)
       { 
           if(gap==1)
           {
               if(s[i]==s[j])
                 {dp[i][j]=true;
                  count[i][j]=2;
                  cout<<s.substr(i,gap+1)<<endl;
                 }

               else 
               {
                   dp[i][j]=false;
                   count[i][j]=1;
               }
           }

           else
           {  if(s[i]==s[j]&&dp[i+1][j-1]==true)
              {  dp[i][j]=true;
                count[i][j]=1+count[i+1][j]+count[i][j-1]-count[i+1][j-1];
                  cout<<s.substr(i,gap+1)<<endl;
              }

              else
              {
                  dp[i][j]=false;
                  count[i][j]=count[i+1][j]+count[i][j-1]-count[i+1][j-1];
              }
              
               
           }
           
       }
   }
   
   int ans=count[0][n-1];
   return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       cin>>s;
       int n=fun(s);
       cout<<"Count="<<n<<endl;

    }
    return 0;
}