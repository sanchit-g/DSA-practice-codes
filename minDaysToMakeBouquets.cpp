class Solution {
public:
    int minDays(vector<int>& arr, int m, int k) {
        
        int n = arr.size();
        
        auto ok = [&](int x)
        {
            int flowers = 0, count = 0;
            
            for(int i = 0; i < n; i++)
            {
                flowers = (arr[i] <= x) ? flowers + 1 : 0;
                if(flowers == k)
                {
                    count++;
                    flowers = 0;
                }
            }
            
            return count >= m;
        };
        
        int low = 0, high = *max_element(arr.begin(), arr.end()), ans = -1;
        
        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            if(ok(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            
            else low = mid + 1;
        }
        
        return ans;
    }
};
