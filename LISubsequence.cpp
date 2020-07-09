//Longest Increasing Subsequence
#include <iostream>
#include<climits>
using namespace std;

int main() {
	
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
           cin>>arr[i];

        int dp[n];

        dp[0]=1;
        int ans=INT_MIN;
        for(int i=1;i<n;i++)
        {   dp[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(arr[j]<arr[i])
                dp[i]=max(dp[i],dp[j]+1);
            }
            ans=max(ans,dp[i]);
        }  
 
        cout<<ans<<endl;
    }


	return 0;
}