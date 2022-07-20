class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    int countSubstringsWithAtmostKUniqueVowels(string s, int k) {
        unordered_map<char, int> mp;
        int count = 0;
        
        int i = 0;
        
        for(int j = 0; j < s.length(); j++)
        {
            if(!isVowel(s[j]))
            {
                i = j + 1;
                mp.clear();
                continue;
            }
            
            mp[s[j]]++;
            
            while(mp.size() > k)
            {
                mp[s[i]]--;
                
                if(mp[s[i]] == 0)
                    mp.erase(s[i]);
                
                i++;
            }
            
            count += (j - i + 1);
        }
        
        return count;
    }
    
    int countVowelSubstrings(string word) {
        return countSubstringsWithAtmostKUniqueVowels(word, 5) - countSubstringsWithAtmostKUniqueVowels(word, 4);
    }
};
