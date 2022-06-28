class Solution {
public:
    int minDeletions(string str) {
        
        int n = str.size();
        unordered_map<char, int> mp;
        
        for(int i = 0; i < n; i++)
            mp[str[i]]++;
        
        int ans = 0;
        set<int> s;
        
        for (auto [i, j] : mp)
        {
            // if we've seen the count of a char before, decrement it until we haven't
            while(s.find(j) != s.end())
            {
                 j--;
                 ans++;
            }
            
            // if this frequency has not been encountered before we will insert it in set   
            if(j > 0) s.insert(j); 
        }
        
        return ans;
    }
};
