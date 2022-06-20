class Solution {
public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        
        auto ok = [&](int mid)
        {
            int groups = 0, sum = 0;

            for (int i = 0; i < n; i++)
            {
                if (arr[i] > mid)
                    return false;

                if (sum + arr[i] > mid)
                {
                    sum = 0;
                    groups++;
                }
                sum += arr[i];
            }

            if (sum > 0)
                groups++;

            return groups <= k;
        };

        int low = 0, ans;
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (ok(mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
};
