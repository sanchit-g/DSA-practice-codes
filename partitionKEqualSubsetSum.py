# similar to Leetcode #235 : https://leetcode.com/problems/fair-distribution-of-cookies/

class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        
        N, total = len(nums), sum(nums)
        
        if total % k != 0:
            return False
        target_sum = total // k
        
        # these are the K buckets in which we will try to place the nums
        ks = [0] * k
        
        # We want to try placing larger numbers first
        # This slightly optimizes the code
        nums.sort(reverse=True)
        
        def solve(j):
            # base case
            if j == N:
                for i in range(k):
                    if ks[i] != target_sum:
                        return False
                return True
            
            for i in range(k):
                # If adding nums[j] to this bucket exceeds the target_sum, no need to continue
                if ks[i] + nums[j] > target_sum:
                    continue
                
                ks[i] += nums[j]
                
                # after adding nums[j] to the current bucket, i.e. ks[i], we try to place the next element
                # if that leads to an answer, then we have correctly placed nums[j] and we're done.
                if solve(j + 1):
                    return True
                
                # otherwise, remove the current element and try to place it in next bucket
                ks[i] -= nums[j]
                
                # an optimization technique (this improves the runtime DRASTICALLY)
                # If ks[i] == 0, it means:
                #   - We put nums[j] into an empty bucket
                #   - We tried placing every other element after and failed
                #   - We took nums[j] out of the bucket, making it empty again 
                # So trying to put nums[j] into a _different_ empty bucket will not produce
                # a correct solution; we will just waste time (we place elements left to right,
                # so if this bucket is now empty, every one after it is too).
                if ks[i] == 0:
                    break
            
            return False
        
        # Start by trying to place nums[0]
        return solve(0)
