//Generate binary string

#include <iostream>
using namespace std;

void generateBinaryString(string s,string cur,vector<string> &ans,int index, int size)
{
   if(index==size)
   {
       ans.push_back(cur);
       return;
   }

   if(s[index]=='0')
   generateBinaryString(s,cur+"0",ans,index+1,size);

   if(s[index]=='1')
   generateBinaryString(s,cur+"1",ans,index+1,size);


   else if(s[index]=='?')
   {
       generateBinaryString(s,cur+"0",ans,index+1,size);
       generateBinaryString(s,cur+"1",ans,index+1,size);
   }
   
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;

        vector<string> ans;
        generateBinaryString(s,"",ans,0,s.length());

        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
	
	return 0;
}