class Solution {
public:
   string getKey(string s)
   {

       sort(s.begin(),s.end());
       return s;
      

   }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string,vector<string>> m;

        for(int i=0;i<strs.size();i++)
        {
            string key=getKey(strs[i]);
            m[key].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;

        for(auto i=m.begin();i!=m.end();i++)
        {
            ans.push_back(i->second);
        }

        return ans;
    }
};