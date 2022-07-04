// Logic : https://leetcode.com/problems/minimum-cost-to-hire-k-workers/discuss/177269/N-log-N-explanation-no-code

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        int N = quality.size();
        vector<pair<double, int>> v;
        
        for(int i = 0; i < N; i++) {
            v.push_back({wage[i]*1.0/quality[i], quality[i]});
        }
        
        sort(v.begin(), v.end());
        
        int total_quality = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < k; i++) {
            total_quality += v[i].second;
            pq.push(v[i].second);
        }
        
        double ans = total_quality * v[k - 1].first;
        
        for(int i = k; i < N; i++) {
            total_quality -= pq.top();
            pq.pop();
            pq.push(v[i].second);
            total_quality += v[i].second;
            ans = min(ans, total_quality * v[i].first);
        }
        
        return ans;
    }
};
