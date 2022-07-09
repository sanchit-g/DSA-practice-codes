class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        
        int N = A.size(), ans = INT_MIN;
        int maxSoFar = -1;
        
        // we need to find max{(A[i] + i) + (A[j] - j)}
        // this means we can find max(A[i] + i) and max(A[j] - j)
      
        // here maxSoFar is the maximum value of (A[i] + i) we have seen till now
        // maxSoFar will be always be a positive value
        
        for(int i = 1; i < N; i++)
        {
            maxSoFar = max(maxSoFar, A[i-1] + i - 1);
            ans = max(ans, maxSoFar + A[i] - i);
        }
        
        return ans;
    }
};
