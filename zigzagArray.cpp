#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
           cin>>arr[i];
        //sort(arr,arr+n);  

        bool flag=true; //<

        for(int i=0;i<n-1;i++)
        {
            if(flag==true)
            {  if(arr[i]>arr[i+1])
                 swap(arr[i],arr[i+1]);
            }

            else 
            {
                if(arr[i]<arr[i+1])
                swap(arr[i],arr[i+1]);
            }

            flag=!(flag);
        }

        for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

        cout<<endl;

    }



	return 0;
}