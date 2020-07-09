#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n,d;
        cin>>n>>d;

        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];

        sort(arr,arr+n);
        int curdiff;

        int start=0; int end=1;
        int ans=-1;
        while(start<end)
        { 
            curdiff=arr[end]-arr[start];
            if(curdiff>k)
            {
                while(curdiff>k)
                {
                    curdiff-=arr[start];
                    start++;
                }
            }


            if(curdiff<k)
            {
               end++;
            }

            if(curdiff==k)
            {
              ans=1;
              break;
            }

        }

        cout<<ans<<endl;


    }



	return 0;
}