#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];

        for(int i=0;i<n;i++)
        cin>>arr[i];

        int ans=-1;
        int sum=arr[0];
        int start=0;
        int end=0;

        while(start<=end&&sum!=k)
        { 
            if(sum<k)
            {
                end++;
                sum+=arr[end];
            }

           if(sum==k)
            {
                ans=0;
                break;
            }

            else if(sum>k)
            {
                while(sum>k)
                {   sum-=arr[start];
                    start++;
                }

                if(sum==k)
               {
                ans=0;
                break;
               }


            }


        }

        if(ans==0)
        {
            cout<<start+1<<" "<<end+1<<endl;
        }

        else
        {
             cout<<ans<<endl;
        }
        

    }	
 


	return 0;
}