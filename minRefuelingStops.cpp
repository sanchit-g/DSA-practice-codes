class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        // Heap solution
        
//         int n = stations.size();
        
//         // max heap
//         priority_queue<int> pq;
//         int curr = startFuel, minStops = 0, i = 0;
        
//         while(curr < target)
//         {
//             while(i < n and curr >= stations[i][0])
//             {
//                 pq.push(stations[i][1]);
//                 i++;
//             }
            
//             if(pq.empty())
//                 return -1;
            
//             curr += pq.top();
//             pq.pop();
//             minStops++;
//         }
        
//         return minStops;
        
        // Dynamic programming solution
        
        int n = stations.size();
        
        vector<vector<long long>> dp(n+1, vector<long long>(n+1, 0));
        
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = startFuel;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= i; j++)
            {
                // if no stop is made
                dp[i][j] = dp[i-1][j];
                
                // check whether we can reach this station from prev station
                if(dp[i-1][j-1] >= stations[i-1][0])
                {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + stations[i-1][1]);
                }
            }
        }
        
        for(int j = 0; j <= n; j++)
        {
            if(dp[n][j] >= target)
                return j;
        }
        
        return -1;
    }
};
