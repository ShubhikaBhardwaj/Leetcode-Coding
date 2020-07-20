#include <iostream>
#include<vector>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        string s1,s2;
        cin>>s1>>s2;

        int dp[a+1][b+1]={0};

        for(int len=1;len<a;len++)
        {
            for(int i=0,j=i+len-1;i<a;i++,j++)
            {
                if(s1[i]==s2[j])
                dp[i][j]=1+dp[i-1][j-1];

                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
                }
                
            }
        }

        int ans=dp[a][b];
        cout<<ans<<endl;
        

    }


	return 0;
}