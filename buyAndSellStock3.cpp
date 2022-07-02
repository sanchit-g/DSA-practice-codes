class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        int dp[n+1][2][3];
        
        memset(dp, 0, sizeof(dp));
        
        for(int ind = n - 1; ind >= 0; ind--)
        {
            for(int buy : {0, 1})
            {
                for(int cap : {1, 2})
                {
                    if(buy == 1)
                    {
                        dp[ind][buy][cap] = max((-prices[ind] + dp[ind+1][0][cap]), dp[ind+1][1][cap]);
                    }
                    
                    else
                    {
                        dp[ind][buy][cap] = max((prices[ind] + dp[ind+1][1][cap-1]), dp[ind+1][0][cap]);
                    }
                }
            }
        }
        
        return dp[0][1][2];
    }
};
