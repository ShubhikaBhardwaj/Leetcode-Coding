//Set kth bit 
#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;

        int num=0;
        int power=1;
        while(n>0)
        {   if(power==k+1)
             num+=pow(2,power);
             
            else if(n&1==1)
              num+=pow(2,power);
             
            power++; 
            n=n>>1;
        }

        cout<<num<<endl;

    }
	return 0;
}