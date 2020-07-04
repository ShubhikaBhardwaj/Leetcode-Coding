#include<iostream.h>
using namespace std;

int height(vector<int> arr)
{
    int h1=0;

    for(int i=1;i<arr.size();i++)
    {
        if(arr[i]<arr[i-1])
        h1++;

        else 
        break;

    }

    int h2=1;
    int val=arr[0];
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>val)
          {
              h2++;
              val=arr[i];
          }
    }
   
   int height_=max(h1,h2);
   return height_;

}


int main()
{
  vector<int>arr={25,20,10,5,1,8,12,15,22,36,30,28,40,38,48,45,50};
  
  int ans=height(arr);
  cout<<ans<<endl; 
    return 0;
}