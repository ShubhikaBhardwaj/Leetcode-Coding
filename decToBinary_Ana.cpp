#include<iostream>
#include<vector>
#include<algorithm>
 using namespace std;

vector<int> toBinary(int a)
{  vector<int> ans;

   while(a>0)
   {
       ans.push_back(a%2);
       a=a/2;
       
   }

    reverse(ans.begin(),ans.end());
    return ans;
}


 int main()
 {
     int a,b;
     cin>>a>>b;

     vector<int> A=toBinary(a);
     vector<int> B=toBinary(b);

     
     for(int i=0;i<A.size();i++)
      cout<<A[i];

      cout<<endl;

      
     for(int i=0;i<B.size();i++)
      cout<<B[i];

      cout<<endl;
      
      sort(A.begin(),A.end());
      sort(B.begin(),B.end());


     for(int i=0;i<A.size()&&B.size();i++)
     {
         if(A[i]!=B[i])
        {
            cout<<"false";
            return 0;
        }
     }
     cout<<"true";
     return 0;
  }
