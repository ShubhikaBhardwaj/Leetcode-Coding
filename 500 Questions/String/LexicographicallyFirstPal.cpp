//Lexicographically first palindromic string
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isPal(string s)
{
    int arr[26]={0};
    for(int i=0;i<s.length();i++)
       arr[s[i]-'a']++;

    int oddCount=0;
    for(int i=0;i<26;i++)   
        if(arr[i]%2==1)
        oddCount++;

    int n=s.length();

    if(n%2==0)
    {
       if(oddCount>0)
       return false;

       else
       return true;
    }   

    else
    {
       if(oddCount!=1)
       return false;

       else
       return true;
        
    }
     

}

string smallPal(string s)
{
    
    int arr[26]={0};
    for(int i=0;i<s.length();i++)
       arr[s[i]-'a']++;

    string odd=" ";
    for(int i=0;i<26;i++)   
        if(arr[i]%2==1)
          { char ch='a'+i;
            odd=ch;
          };

    string start="";
    string end="";
    for(int i=0;i<26;i++)
    {
       if(arr[i]!=0&&arr[i]!=1)
       {
           for(int k=0;k<arr[i]/2;k++)
           {
            char ch=(char)('a'+i);
            start+=ch;
            end+=ch;
           }
       }
    }   
    
    reverse(end.begin(),end.end());
    string ans=start+odd+end;
    return ans;     

}


int main()
{  string s;
   cin>>s;

   if(isPal(s)==false)
   {
       cout<<"no palindromic string\n";
   }

   else
   {
       string ans=smallPal(s);
       cout<<ans<<endl;
   }
   

    return 0;
}

