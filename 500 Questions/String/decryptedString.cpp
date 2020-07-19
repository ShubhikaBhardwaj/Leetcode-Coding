//Find k’th character of decrypted string
#include<iostream>
#include<string>

using namespace std;

string decrypt(string &s)
{   string ans="";
    int i;
    string small;
    int num;
    for(i=0;i<s.length();)
    { small="";
      num=0;
    
        while(s[i]>='a'&&s[i]<='z'&&i<s.length())
        {
            small+=s[i];
            i++;
        }

        while(s[i]>='0'&&s[i]<='9'&&i<s.length())
        {
            int x=s[i]-'0';
            num=(10*num)+x;
            i++;
        }
        
        if(num>0)
        {
        for(int j=0;j<num;j++)
        {
            ans+=small;
        }
        }

        else
        {
            ans+=small;
        }
        
        cout<<"* "<<ans<<endl;


    }

   return ans;
}


int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;

    string ans=decrypt(s);
    cout<<ans<<endl;
    cout<<ans[k-1]<<endl;

    return 0;
}