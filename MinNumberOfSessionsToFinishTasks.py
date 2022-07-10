# Similar to Leetcode #698 : https://leetcode.com/problems/partition-to-k-equal-sum-subsets/

# For a given value of k, you can check if you can have k-subsets 
# where none of the sums exceeds sessionTime. Start from the lowest possible 
# value of k and try if you can solve.

class Solution:
    def minSessions(self, tasks: List[int], sessionTime: int) -> int:
        
        N, total = len(tasks), sum(tasks)
        
        if total <= sessionTime:
            return 1
        
        tasks.sort(reverse=True)
        
        k_min, k_max = total // sessionTime, N
        
        for k in range(k_min, k_max):
            ks = [0] * k
            
            def solve(j):
                if j == N:
                    for i in range(k):
                        if ks[i] > sessionTime:
                            return False
                    return True
            
                for i in range(k):
                    if ks[i] + tasks[j] > sessionTime:
                        continue
                
                    ks[i] += tasks[j]
                
                    if solve(j + 1):
                        return True
                
                    ks[i] -= tasks[j]
                
                    if ks[i] == 0:
                        break
            
                return False
            
            if solve(0):
                return k
        
        return N
