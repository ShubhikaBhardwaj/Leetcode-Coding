//Count of total anagram substrings
#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int fun(string s)
{
    //vector<int>arr(26,0);
    int n=s.length();
    map<vector<int>,int> m;
    
    
 for(int i=0;i<n;i++)
    {vector<int>arr(26,0);
    
        for(int j=i;j<n;j++)
        {
            arr[s[j]-'a']++;

            m[arr]++;
        }
    }

    int count=0;
    for(auto i=m.begin();i!=m.end();i++)
    {  int freq=i->second;
        count+=((freq)*(freq-1))/2;
    }

    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
        cin>>s;
       int ans=fun(s);
       cout<<ans<<endl;

    }
    return 0;
}