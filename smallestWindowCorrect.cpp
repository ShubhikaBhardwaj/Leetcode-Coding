//Smallest window in a string containing all the characters of another string

#include<bits/stdc++.h>
using namespace std;

string fun(string s,string pat)
 {   int N=s.length();
     int M=pat.length();

     if(M>N)return "-1";

     int arr1[256];
     int arr2[256];
     
     for(int i=0;i<256;i++)
     {
         arr1[i]=0;
         arr2[i]=0;
     }

     for(int i=0;i<M;i++)
     {
         arr2[pat[i]]++;
     }

      int count=0;
      int start=0;
      int startIndex=-1;
      int minlen=INT_MAX;
     for(int i=0;i<N;i++)
     {
        arr1[s[i]]++;

        if(arr2[s[i]]!=0&&arr1[s[i]]<=arr2[s[i]])
        count++;

        if(count==M)
        {
            while(arr2[s[start]]==0||arr1[s[start]]>arr2[s[start]])
            {
                if(arr1[s[start]]>arr2[s[start]])
                  { arr1[s[start]]--;}

                start++;
            }
          
           int len=i-start+1;

           if(len<minlen)
           {
               minlen=len;
               startIndex=start;
           }

        }


     }

    if(startIndex==-1)
    {
        return "-1";
    }
    
     return s.substr(startIndex,minlen);
 }

int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string s;
        string pat;
        cin>>s;
        cin>>pat;

       cout<<fun(s,pat)<<endl;
        
    }
    return 0;
}