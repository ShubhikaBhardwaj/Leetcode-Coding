//First non-repeating character in a stream

#include <iostream>
using namespace std;

void addNode

int main() {
	//code
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        vector<int>q;
        int k=0;
        int arr[256];
        for(int i=0;i<n;i++)
        {
           int x;
           cin>>x;
           q.push(x);

           arr[x]++;

           if(q[k]==x)
           {
               while(arr[q[k]]!=1)
               k++;
           }

        if(k>i)
        {
            cout<<"-1 ";
            k=i;
        }


           else if(arr[q[k]]==1)
           {
               cout<<q[k]<<" ";
           }

        }
        
        cout<<endl;
    }


	return 0;
}