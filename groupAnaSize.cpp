#include <iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int main() {
	int t;
    while(t--)
    {
        int n;
        vector<string> arr;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            arr.push_back(s);
        }

        map<string,int>m;
        
        for(int i=0;i<n;i++)
        {
            
            sort(arr[i].begin(),arr[i].end());

            m[arr[i]]++;
        }

        for(auto i=m.begin();i!=m.end();i++)
        {
            cout<<i->second<<" ";
        }

       cout<<endl;
    }
	return 0;
}