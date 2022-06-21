class Solution {
public:
    const int M = 1000000007;
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // pre-compute powers
        vector<int> powers(n+1, 1);
        for(int i = 1; i <= n; i++)
            powers[i] = (powers[i-1] * 2) % M;
        
        int i = 0, j = n - 1;
        int count = 0;
        
        while (i <= j)
        {
            if(nums[i] + nums[j] <= target)
            {
                count = (count + powers[j-i]) % M;
                i++;
            }
            
            else j--;
        }
        
        return count;
    }
};
