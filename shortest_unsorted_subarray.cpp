#define MAX 100001
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = -1, right = n - 1;
        
        // First pass
        // Iterate from the end, and check weather the element at index "i" is the current minimum element or not.
        // If not then "i" is the starting index
        int curr_min = MAX;
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] <= curr_min)
                curr_min = nums[i];
            if(nums[i] > curr_min)
                left = i;
        }
        
        // Second pass
        // Iterate from the start, and check weather the element at index "i" is the current maximum element or not.
        // If not then "i" is the ending index
        int curr_max = -MAX;
        for(int i = 0; i < n; i++) {
            if(nums[i] >= curr_max)
                curr_max = nums[i];
            if(nums[i] < curr_max)
                right = i;
        }
        
        // cout << left << " " << right << endl;
        
        // If no starting point is found, it means array is already sorted
        return left == -1 ? 0 : (right - left + 1);
    }
};
