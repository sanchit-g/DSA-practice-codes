class Solution {
public:
    
    bool isAnagram(vector<int>& s_count, vector<int>& p_count) {
        for(int i = 0; i < 26; i++)
        {
            if(s_count[i] != p_count[i])
                return false;
        }
        
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        
        int n = s.length(), m = p.length();
        
        vector<int> p_count(26, 0);
        for(int i = 0; i < m; i++)
            p_count[p[i] - 'a']++;
        
        int j = 0;
        vector<int> startIndices;
        vector<int> s_count(26, 0);
        
        for(int i = 0; i < n; i++) {
            while((j - i + 1) <= m and j < n) {
                s_count[s[j] - 'a']++;
                j++;
            }
            
            if(isAnagram(s_count, p_count)) {
                startIndices.push_back(i);
            }
            
            s_count[s[i] - 'a']--;
        }
        
        return startIndices;
    }
};
