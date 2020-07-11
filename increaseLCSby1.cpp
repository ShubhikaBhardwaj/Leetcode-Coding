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

        int lcs[a+2][b+2];
        int rlcs[a+2][b+2];

        for(int i=0;i<a+2;i++)
        {
            for(int j=0;j<b+2;j++)
            {
                lcs[i][j]=0;
                rlcs[i][j]=0;
            }
        }

        for(int i=1;i<a+1;i++)
        {
            for(int j=1;j<b+1;j++)
            {
                if(s1[i-1]==s2[j-1])
                lcs[i][j]=1+lcs[i-1][j-1];

                else
                {
                    lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
                }
                
            }
        }

        for(int i=a;i>=1;i--)
        {
            for(int j=b;j>=1;j--)
            {
                
                if(s1[i-1]==s2[j-1])
                rlcs[i][j]=1+rlcs[i+1][j+1];

                else
                {
                    rlcs[i][j]=max(rlcs[i+1][j],rlcs[i][j+1]);
                }

            }
        }

        vector<int>positions[26];

        for(int i=0;i<b;i++)
        {
            int x=(int)(s2[i]-'a');
            positions[x].push_back(i+1);
        }

        int ways=0;

        for(int i=0;i<=a;i++)
        {
            for(char c='a';c<='z';c++)
            {
                for(int p=0;p<positions[(int)(c-'a')].size();p++)
                {
                    int P=positions[(int)(c-'a')][p];
                   if(lcs[i][P-1]+rlcs[i+1][P+1]==lcs[a][b])
                    {ways++;  
                     string ans=s1.substr(0,i)+to_string(c)+s1.substr(i);
                //   cout<<s1.substr(0,i-1);
                //   cout<<c;
                //   cout<<s1.substr(i)<<endl;
                
                    }    
                }
            }
        }
        
        cout<<ways<<endl;

    }
	return 0;
}