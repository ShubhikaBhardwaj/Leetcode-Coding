#include<iostream>
using namespace std;

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       string s;
       cin>>s;

    int odd=0,even=0;
       for(int i=0;i<s.length();i++)
       {
           if(s[i]=='1')
           {
               if(i%2==0)even++;
               else odd++;
           }

       }

       if((odd-even)%3==0)
       return true;

       return false;
   }


    return 0;
}