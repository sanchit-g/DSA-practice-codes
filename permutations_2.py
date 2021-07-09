class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        
        def recur(path, hashmap):
            if len(path) == len(nums):
                res.append(list(path))
            # we use hashmap to avoid duplicate values
            for val in hashmap:
                if hashmap[val] > 0:
                    path.append(val)
                    hashmap[val] -= 1
                    recur(path, hashmap)
                    path.pop()
                    hashmap[val] += 1
                    
        hashmap = {}
        for num in nums:
            if num in hashmap:
                hashmap[num] += 1
            else:
                hashmap[num] = 1
        res = []
        recur([], hashmap)
        return res
