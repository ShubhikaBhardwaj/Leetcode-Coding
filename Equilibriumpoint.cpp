//Equilibrium point
#include <iostream>
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
           
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }

        int leftSum[n];
       // int rightSum[n];

        leftSum[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            leftSum[i]=leftSum[i-1]+arr[i];
        }

        rightSum[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightSum[i]=rightSum[i+1]+arr[i];
        }

        int idx=-1;
        for(int i=0;i<n;i++)
        {
            if(leftSum[i]==rightSum[i])
            {
                idx=i;
                break;
            }
        }
        
        if(idx==-1)
        cout<<-1<<endl;
        
        else
        cout<<idx+1<<endl;


    }


	return 0;
}