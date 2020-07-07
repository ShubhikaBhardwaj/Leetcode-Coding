class Solution {
public:
   
    vector<int> majorityElement(vector<int>& arr) {

        //Using Moore's Voting Algorithm

        int n=arr.size();
        vector<int> ans;
        int count1=0,count2=0;
        int first=-1,second=-1;

        for(int i=0;i<n;i++)
        {
            if(arr[i]==first)
            {
                count1++;
            }

            else if(arr[i]==second)
            {
                count2++;
            }

            else if(count1==0)
            {
                first=arr[i];
                count1=1;
            }

            else if(count2==0)
            {
                second=arr[i];
                count2=1;
            }

            else
            {
                count1--;
                count2--;
            }
        
        }

        int c1=0,c2=0;
        for(int i=0;i<n;i++)
        {
           if(arr[i]==first)
           c1++;

           if(arr[i]==second)
           c2++;

        }

       if(c1>n/3)return first;

       if(c2>n/3)return second;

       return -1;
        
    }
};