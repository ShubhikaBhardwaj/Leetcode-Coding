//MS
//Key Pair Question
//Concept->HAShmap

#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x;
        cin>>x;
        
        int arr[n];
        for(int i=0;i<n;i++)
          cin>>arr[i];

        map<int,int>m;

        bool ans=false;

        for(int i=0;i<n;i++)  
        {
            if(m.find(x-arr[i])!=m.end())
            {
                ans=true;
                break;
            }

            else 
            m[arr[i]]++;
        }

        if(ans==true)
        cout<<"Yes"<<endl;

        else 
        cout<<"No"<<endl;


    }



	return 0;
}