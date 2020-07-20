#include <iostream>
#include<string>
#include<climits>
using namespace std;

int fun(string s)
{
   int dis_char=0;
   int arr[256]={0};

   for(int i=0;i<s.size();i++)
   {
       arr[s[i]-'a']++;
   } 

   for(int i=0;i<256;i++)
   {
       if(arr[i]>=1)
       dis_char++;
   }

   int start=0,startIndex=-1,curlen=0, maxlen=INT_MIN;
   int cur_count=0;

   int arr1[256]={0};
   for(int i=0;i<s.length();i++)
   {
       arr1[s[i]-'a']++;

       if(arr1[s[i]-'a']==1)
       cur_count++;

       if(cur_count==dis_char)
       {
           while(arr1[start]>1)
            if(arr1[start]>1)
              {   arr1[start]--;
                  start++;
              }
       }
       
       curlen=i-start+1;

       if(curlen>maxlen)
       {
           maxlen=curlen;
           startIndex=start;
       }

   }
   
   cout<<s.substr(startIndex,maxlen);
   return maxlen;
}



int main() {
	//code
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