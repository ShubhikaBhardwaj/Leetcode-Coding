//Longest Non-palindromic substring
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool isPal(string s)
{
   int start=0;
   int end=s.length()-1;
   while(start<=end)
   {
     if(s[start]!=s[end])
       return false;
       start++;
       end--;
   }

   return true;
}

int main()
{  string s;
   cin>>s;
   
   char ch=s[0];
   int i;
   for(i=1;i<s.length();i++)
   {  
       if(s[i]!=ch)
       break;

   }

   int n=s.length();

   if(i==s.length())
   cout<<0;

   else if(isPal(s))
       cout<<n-1;
   
   else 
   cout<<n;   

    return 0;
}

