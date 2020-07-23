//Swap every two bits in bytes
#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        int a=n&0xAAAAAAAA;
        a=a>>1;
        int b=n&0x55555555;
        b=b<<1;

        cout<<(a|b)<<endl;

    }
	return 0;
}