//Kadane -Maximum SubArray Sum
#include<iostream>
#include<climits>
using namespace std;

int kadane(int *arr,int n)
{
    int maxSum= INT_MIN;
    int cursum=0;
    
    for(int i=0;i<n;i++)
    {
        cursum+=arr[i];
        if(cursum<0)
        cursum=0;

        maxSum=max(maxSum,cursum);
    }

   return maxSum;
}


int main()
{
    int arr[]={1,2,3,5,0,-9};

    int ans=kadane(arr,6);
    cout<<ans<<endl;
    return 0;
}

