//Print all distinct characters of a string in order

#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;

string fun(string s)
{
   int arr[256]={0};
   string ans="";
   for(int i=0;i<s.length();i++)
   {
       arr[s[i]]++;
   }

 for(int i=0;i<s.length();i++)
     {
       if(arr[s[i]]==1)
       ans+=s[i];
   }
   
  return ans;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
       string s;
       getline(cin,s,'.');
       string ans=fun(s);
       cout<<ans<<endl;

    }
    return 0;
}