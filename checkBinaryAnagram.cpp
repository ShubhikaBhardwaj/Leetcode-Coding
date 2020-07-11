#include<iostream>
 using namespace std;

 int main()
 {
     int a,b;
     cin>>a>>b;

     int a1=0,a0=0;
     int b1=0,b0=0;

     while(a!=0)
     {
         if((a&1)>0)a1++;
         else a0++;

         a=a>>1;
     }


     while(b!=0)
     {
         if((b&1)>0)b1++;
         else b0++;

         b=b>>1;
     }

    cout<<"A "<<a0<<" "<<a1<<endl;
    cout<<"B "<<b0<<" "<<b1<<endl;

     if(a1==b1)
     cout<<"true"<<endl;

     else cout<<"false"<<endl;
     return 0;
 }
