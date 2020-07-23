//Set kth bit 
#include <iostream>
using namespace std;

string fun(int n,int k)
{
    if(((1<<k)&n)==1)
    return "Yes";

    return "No";
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;

        string ans=fun(n,k);
        cout<<ans<<endl;

    }
	return 0;
}