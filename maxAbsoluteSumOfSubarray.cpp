class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int mx1 = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum < 0)
                sum=0;
            mx1 = max(sum, mx1);
        }
        
        int mx2 = 0;
        sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum > 0)
                sum = 0;
            mx2 = min(sum, mx2);
        }
        
        return max(mx1, abs(mx2));
    }
};
