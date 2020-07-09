#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n; // no of packets
        cin>>n;

        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int m; //no of children
        cin>>m;

        if(n==0||m==0)
        {
            cout<<0<<endl;
            continue;
        }
        
        if(m>n)
        {
            cout<<-1<<endl;
            continue;
        }

        sort(arr,arr+n);

        int mindiff=INT_MAX;
        int diff;
        for(int i=0;i+m<n;i++)
        {
            diff=arr[i+m]-arr[i];
            mindiff=min(mindiff,diff);
            
        }
        
        cout<<mindiff<<endl;
        
    }



	return 0;
}