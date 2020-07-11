#include <iostream>
#include<string>
using namespace std;

bool isAna(string s,int arr2[256])
{
    int arr1[256]={0};
    for(int i=0;i<s.length();i++)
    {
        int x=s[i];
        arr1[x]++;
    }

    for(int i=0;i<256;i++)
    {
        if(arr1[i]!=arr2[i])
        return false;
    }
   
   return true;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        string s;
        string pat;
        //int arr1[256]={0};
        int arr2[256]={0};

        cin>>s>>pat;

        for(int i=0;i<pat.length();i++)
        {  int x=pat[i];
            arr2[x]++;
        }
        
        int count=0;
        for(int i=0;i<s.length();i++)
        {
            string small=s.substr(i,pat.length());
            if(isAna(small,arr2)==true)
            count++;
        }

        cout<<count<<endl;

    }
	return 0;
}