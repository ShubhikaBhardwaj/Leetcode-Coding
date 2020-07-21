//Count and Say

//Topic:- Recursion
class Solution {
public:
  
    string fun(string s)
    {
       int freq=0;
       string ans="";

       for(int i=0;i<s.length();)
       {    
           freq=0;
           char ch=s[i];
           while(s[i]==ch)
           {
               freq++;
               i++;
           }
 
           ans+=to_string(freq)+ch;

       }

       return ans;
    }


    string countAndSay(int n) {
        
        string num="1";
        
        for(int i=0;i<n-1;i++)
        {
           num=fun(num);
        }
         
        return num; 
        
    }
};