#include <iostream>
#include<utility>
using namespace std;

//Longest palindrome Substring

int main() {

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        int n=s.length();
    

        bool dp[n][n];
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         dp[i][j]=false;
         
         
        int start=0;
        int maxlen=1;


        for(int len=1;len<=n;len++)
        {
            for(int i=0;i+len-1<n;i++)
            {  int j=i+len-1;
                if(len==1)
                {
                    dp[i][j]=true;
                    
                        if(len>maxlen)
                        {
                            maxlen=1;
                            start=i;
                        }
                }

                else if(len==2)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=true;
                        
                        if(len>maxlen)
                        {
                            maxlen=len;
                            start=i;
                        }
                    
                    }
                }

                else
                {
                    if(s[i]==s[j]&&dp[i+1][j-1])
                    {
                        dp[i][j]=true;
                        //int len=j-i+1;

                        if(len>maxlen)
                        {
                            maxlen=len;
                            start=i;
                        }
                    }
                    
                    
                }
                
            }
        }
         
         cout<<s.substr(start,maxlen)<<endl;


    }

	return 0;
}