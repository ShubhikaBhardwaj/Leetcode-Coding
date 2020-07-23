//ReverseBits

#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        vector<char> ans;

        int x=n;
        
        for(int i=0;i<32;i++)
        {
            if((1<<i)&n)
            ans.push_back('1');

            else
            ans.push_back('2');
        }

        reverse(ans.begin(),ans.end());

        int num=0;
        for(int i=0;i<32;i++)
        {
            if(ans[i]=='1')
            {
                num=num|(1<<i);
            }
        }

        cout<<num<<endl;
    }
	return 0;
}    