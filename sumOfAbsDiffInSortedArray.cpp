class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> prefix(n + 1, 0);
        
        prefix[1] = nums[0];
        
        for(int i = 2; i <= n; i++)
            prefix[i] = prefix[i - 1] + nums[i - 1];
        
        vector<int> diff(n, 0);
        
        for(int i = 0; i < n; i++) {
            int pos = (i * nums[i]) + prefix[n] - prefix[i+1];
            int neg = ((n - i - 1) * nums[i]) + prefix[i];
            
            diff[i] = pos - neg;
        }
        
        return diff;
    }
};
