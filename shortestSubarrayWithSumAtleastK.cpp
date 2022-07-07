class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        // min heap
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        long long sum = 0, ans = 1e18;
        
        for(long long i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum >= k)
                ans = min(ans, i + 1);
            
            while(!pq.empty() and sum - pq.top().first >= k)
            {
                ans = min(ans, i - pq.top().second);
                pq.pop();
            }
            
            pq.push(make_pair(sum, i));
        }
        
        return ans == 1e18 ? -1 : ans;
    }
};
