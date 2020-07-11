bool areKAnagrams(string str1, string str2, int k)
  {
  
     if(str1.length()!=str2.length())
     return false;

     if(str1.length()==0)
     return true;

     int arr1[26]={0};
     int arr2[26]={0};

     for(int i=0;i<str1.length();i++)
     {
         arr1[str1[i]-'a']++;
     }

     for(int i=0;i<str2.length();i++)
     {
         arr2[str2[i]-'a']++;
     }

     int count=0;
     for(int i=0;i<26;i++)
     {
         arr1[i]=arr1[i]-arr2[i];
         count+=abs(arr1[i]);
     }

     if(count<=k)return true;

     return false;

   }