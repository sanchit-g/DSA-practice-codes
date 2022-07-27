// Soln Explanation : https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step

#define MOD 1000000007

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        
        int n = A.size();
        
        stack<pair<int, int>> s1, s2;
        
        // left is for the distance to previous less element
        // right is for the distance to next less element
        vector<int> left(n), right(n);
        
        // initialize
        for(int i = 0; i < n; i++) right[i] = n - i;
        
        for(int i = 0; i < n; i++) {
            // for previous less
            while(!s1.empty() and s1.top().first > A[i])
                s1.pop();
            
            left[i] = s1.empty() ? i + 1 : i - s1.top().second;
            s1.push({A[i], i});
            
            // for next less
            while(!s2.empty() and s2.top().first > A[i]) {
                auto x = s2.top();
                s2.pop();
            
                right[x.second] = i - x.second;
            }
            s2.push({A[i], i});
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            long long prod = (left[i] * right[i]) % MOD;
            prod = (prod * A[i]) % MOD;
            ans = (ans + prod) % MOD;
        }
        
        return ans;
    }
};
