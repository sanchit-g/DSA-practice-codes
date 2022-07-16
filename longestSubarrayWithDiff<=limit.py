# maintain two monotonic queues

class Solution:
    def longestSubarray(self, nums: List[int], limit: int) -> int:
        incQueue, decQueue = deque(), deque()
        l = 0
        ans = 0
        
        for r in range(len(nums)):
            while incQueue and nums[incQueue[-1]] >= nums[r]:
                incQueue.pop()
            
            while decQueue and nums[decQueue[-1]] <= nums[r]:
                decQueue.pop()
                
            incQueue.append(r)
            decQueue.append(r)
            
            while nums[decQueue[0]] - nums[incQueue[0]] > limit:
                l += 1
                if l > incQueue[0]:
                    incQueue.popleft()
                if l > decQueue[0]:
                    decQueue.popleft()
                
            ans = max(ans, r - l + 1)
        
        return ans
