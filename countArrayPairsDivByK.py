class Solution:
    def countPairs(self, nums: List[int], k: int) -> int:
        N, ans = len(nums), 0
        
        # count stores the count of numbers in nums which is divisible by a certain key
        count = defaultdict(int)
        
        # divisors stores the possible values of k / gcd(k, nums[i]), i.e. all the divisors of k
        divisors = []
        
        for i in range(1, k + 1):
            if k % i == 0:
                divisors.append(i)
        
        for i in range(0, N):
            minNum = k // math.gcd(k, nums[i])
            # add to ans the number of elements in nums which are divisible by minNum
            ans += count[minNum]
            
            for divisor in divisors:
                if nums[i] % divisor == 0:
                    count[divisor] += 1
        
        return ans
