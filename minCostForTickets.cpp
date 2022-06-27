class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n = days.size();
        
        vector<int> dp(days[n - 1] + 1);
        
        dp[0] = 0;
        
        for(int i = 1, j = 0; i <= days[n - 1]; i++)
        {
            if(i == days[j])
            {
                dp[i] = min(dp[i - 1] + costs[0], min(dp[i - min(i, 7)] + costs[1], dp[i - min(i, 30)] + costs[2]));
                j++;
            }
            
            else dp[i] = dp[i - 1];
        }
        
        return dp[days[n - 1]];
    }
};
