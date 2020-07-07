class Solution {
public:
    
long long kadane(vector<int>& arr,int n)
{
    
long long maxSum=-1e18;
    
long long cursum=0;
    
    for(int i=0;i<n;i++)
    {
        cursum+=arr[i];
        if(cursum<0)
        cursum=0;

        maxSum=max(maxSum,cursum);
    }
   //cout<<"kadane "<<maxSum<<endl;
   return maxSum;
}

long long maxPrefixSum(vector<int>& arr,int n)
{   
long long maxSum=-1e18;
    
long long sum=0;

    for(int i=0;i<n;i++)
    {
       sum+=arr[i];
       maxSum=max(maxSum,sum);
    }
   //cout<<"p "<<maxSum<<endl;
    return maxSum;

}

long long maxSuffixSum(vector<int>& arr,int n)
{long long maxSum=-1e18;
    
long long sum=0;

    for(int i=n-1;i>=0;i--)
    {
        sum+=arr[i];
        maxSum=max(maxSum,sum);
    }
 //cout<<"s "<<maxSum<<endl;
    return maxSum;

}

long long totalSum(vector<int>& arr,int n)
{ long long sum=0;

    for(int i=0;i<n;i++)
        sum+=arr[i];

     return sum;   
}


long long kConcat(vector<int>& arr,int n,int k)
{

   long long kdSum=kadane(arr,n);
   long long pSum=maxPrefixSum(arr,n);
   long long sSum=maxSuffixSum(arr,n);
   long long tSum=totalSum(arr,n);
   
   if(k==1)
   return kdSum;

   if(tSum>=0)
   {
       return max(kdSum,pSum+sSum+(k-2)*tSum);
   }

   else 
   {  return max(pSum+sSum,kdSum);
   }


}


    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
            long long ans=kConcat(arr,n,k);
            int sol=ans%1000000007;

            return sol;
    }
};