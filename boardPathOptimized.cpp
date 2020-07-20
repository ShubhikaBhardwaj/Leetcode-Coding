#include<iostream>
#include<queue>

//0-10 board
// dice 1 to 6

//Ans= 492
int fun(int n)
{
   queue<int> q;
   int prev=1;

   for(int i=0;i<=n;i++)
   {
       if(i<2)
       q.push(1);

       else if(q.size()<=6)
       {
         q.push(prev*2);
         prev=prev*2;
       }

       else
       {
           int rm=q.front();
           q.pop();
           q.push(2*prev-rm);
           prev=2*prev-rm;
       }
       
       
   }

   return prev;

}


int main()
{
    int n=10;
    cout<<fun(n);
    cout<<endl;
    return 0;
}