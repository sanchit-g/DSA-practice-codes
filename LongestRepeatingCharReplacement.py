class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        
        freq = collections.defaultdict(int)
        i, ans = 0, 0
        
        for j in range(len(s)):
            freq[s[j]] += 1
            
            while (j - i + 1) - max(freq.values()) > k:
                freq[s[i]] -= 1
                i += 1
            
            ans = max(ans, j - i + 1)
        
        return ans
