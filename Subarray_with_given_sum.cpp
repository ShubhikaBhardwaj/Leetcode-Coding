//Subarray with given sum

//Concept->Sliding Window Protocol
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

        bool ans=false;
        int start=0,end=0;
        int cursum=0;
        for(int i=0;i<n;i++)
        {
            cursum+=arr[i];
            end=i;
            if(cursum>k)
            {  
                while(cursum>k&&start<=end)
                {
                    cursum-=arr[start];
                    start++;
                }
            }

            if(cursum==k)
            {   
                cout<<start+1<<" "<<end+1<<endl;
                ans=true;
                break;
            }
        }
   
        if(ans==false)
        cout<<-1<<endl;


    }



	return 0;
}