//Count of words whose i-th letter is either (i-1)-th, i-th, or (i+1)-th letter of given word
#include<iostream>
#include<string>

using namespace std;

int fun(string s)
{
  int n=s.length();
  int count=1;
  if(n==1) return count;

  if(s[0]==s[1])
    count*=1;

  else count*=2;

  for(int i=1;i<n-1;i++)
  {
      if(s[i]==s[i-1]&&s[i]==s[i+1])
      count*=1;

      else if(s[i]==s[i-1]||s[i]==s[i+1])
      count*=2;

      else
       count*=3;
     
  }

  
  if(s[n-1]==s[n-2])
    count*=1;

  else count*=2;


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
       int n=fun(s);
       cout<<n<<endl;

    }
    return 0;
}