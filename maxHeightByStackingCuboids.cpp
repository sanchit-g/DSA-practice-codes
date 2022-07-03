class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        
        // variation of LIS
        
        int n = cuboids.size();
        vector<int> dp(n);
        int ans = 0;
        
        // sort according to sum of all three values
        sort(cuboids.begin(), cuboids.end(), [](auto &a, auto &b) {
           return a[0] + a[1] + a[2] < b[0] + b[1] + b[2]; 
        });
        
        // if we stack only a single cuboid
        int i = 0;
        for(auto &c : cuboids) {
            sort(c.begin(), c.end());
            dp[i] = c.back();
            i++;
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                auto &c1 = cuboids[i];
                auto &c2 = cuboids[j];
                
                if(c1[0] >= c2[0] and c1[1] >= c2[1] and c1[2] >= c2[2])
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
            
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};
