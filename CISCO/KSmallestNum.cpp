//KSmallestNum
#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<int>arr;
        for(int i=0;i<n;i++)
        cin>>arr[i];

        int k;
        cin>>k;

        priority_queue<int,vector<int>,greater<int>> pq;

        for(int i=0;i<n;i++)
        pq.push(arr[i]);

        int x=0;
        while(k--)
        {
            x=pq.top();
            pq.pop();
        }

        cout<<x<<endl;

    }
	return 0;
}