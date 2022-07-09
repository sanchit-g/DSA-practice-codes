class Solution:
    def maxLength(self, arr: List[str]) -> int:
        N = len(arr)
        
        def hasUniqueChars(s1, s2):
            union = s1.union(s2)
            return len(union) == len(s1) + len(s2)
        
        def solve(i, charset):
            if i == N:
                return len(charset)
            
            length = 0
            
            # pick the arr[i]
            if hasUniqueChars(charset, arr[i]):
                length = solve(i+1, charset.union(arr[i]))
            
            # Not pick
            return max(length, solve(i+1, charset))
        
        return solve(0, set())
