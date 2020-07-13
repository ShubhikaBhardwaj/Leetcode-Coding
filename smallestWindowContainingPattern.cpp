//Smallest window in a string containing all the characters of another string

#include <iostream>
#include<climits>
#include<string>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        string s,pat;
        cin>>s>>pat;
        
        if(pat.length()>s.length())
        {
         cout<<-1<<endl;
         continue;   
        }


        int arr1[256]={0};
        int arr2[256]={0};

        for(int i=0;i<pat.length();i++)
        {
            arr2[pat[i]]++;
        }

        int minlen=INT_MAX,start=0,startIndex=-1;
        int count=0;
        int M=pat.length();
        
        for(int i=0;i<s.length();i++)
        {   int charIndex=s[i];
            arr1[charIndex]++;

            if(arr2[charIndex]!=0&&arr1[charIndex]<arr2[charIndex])
            count++;

            if(count==M)
            {
                while(arr2[s[start]]==0||arr1[s[start]]>arr2[s[start]])
                {
                    if(arr1[s[start]]>arr2[s[start]])
                     arr1[s[start]]--;

                    start++;
                }

            }

            int len=i-start+1;
            if(len<minlen)
            {
                minlen=len;
                startIndex=start;
            }
            

        }
        if(startIndex==-1)  // no window possible
        {
         cout<<-1<<endl;
        // continue;   
        }
        
        else
        {       
        string ans=s.substr(startIndex,minlen);
        cout<<ans<<endl;
        }

    }




	return 0;
}