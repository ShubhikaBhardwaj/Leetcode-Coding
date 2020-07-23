//Euler Totient Function
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0)
    return a;

    
    return gcd(b,a%b);
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int count=0;
       
        for(int i=1;i<=n;i++)
        {
            if(gcd(i,n)==1)
            count++;
            
            //else 
            //cout<<gcd(i,n)<<endl;
        }

        cout<<count<<endl;
        
    }
	return 0;
}