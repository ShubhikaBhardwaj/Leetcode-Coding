//Make largest palindrome by changing at most K-digits
#include<iostream>
#include<string>

using namespace std;

string fun(string s,int k)
{
   int start=0;
   int end=s.length()-1;

   string pal=s;

   while(start<=end)
   {
      if(s[start]!=s[end])
      {
          pal[start]=pal[end]=max(s[start],s[end]);
          k--;
      }
      start++;
      end--;
   }
  
  if(k<0)
  return "-1";

  start=0;
  end=s.length()-1;

  while(start<=end)
  {
    if(start==end&&k>=1) //mid
    {
        pal[start]='9';
        k--;
    }

     if(pal[start]<'9')  
     { 
         if(pal[start]==s[start]&&pal[end]==s[end]&&k>=2)
         {
             pal[start]='9';
             pal[end]='9';
             k-=2;
         }

         else if(k>=1&&(pal[start]!=s[start]||pal[end]!=s[end]))
        {
           
             pal[start]='9';
             pal[end]='9';
             k-=1; 
        }

     }
      start++;
      end--;
  }

  return pal;


}

int main()
{
   string s;
   cin>>s;
   int k;  cin>>k;

   string ans=fun(s,k);
   cout<<ans<<endl;

    return 0;
}