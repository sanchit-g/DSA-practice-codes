// Time complexity : O(N*log(N))
// better solution using sliding window possible

class Solution {
public:
    int maxConsecutiveAnswers(string A, int K) {
        
        int n = A.length();
        
        auto isPossible = [&](int x) {
            
            int t_count = 0, f_count = 0;
            
            for(int i = 0; i < x; i++)
            {
                if(A[i] == 'T')
                    t_count++;
                
                else
                    f_count++;
            }
            
            if(min(t_count, f_count) <= K)
                return true;
            
            int l = 0, r = x - 1;
            
            // slide the window of size x towards right (n - x) number of times
            int slide = n - x;
            
            while(slide--)
            {
                if(A[l] == 'T')
                    t_count--;
                
                else
                    f_count--;
                
                l++;
                r++;
                
                if(A[r] == 'T')
                    t_count++;
                
                else
                    f_count++;
                
                if(min(t_count, f_count) <= K)
                    return true;
            }
            
            return false;
        };
        
        int low = 1, high = n, mid, ans = 1;
        
        while(low <= high)
        {
            mid = low + (high - low) / 2;
            
            if(isPossible(mid)) {
                ans = mid;
                low = mid + 1;
            }
            
            else
                high = mid - 1;
        }
        
        return ans;
    }
};
