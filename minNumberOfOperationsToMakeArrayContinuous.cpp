// first sort the array and remove all the duplicate elements
// now pick each element nums[i] as the start of the subarray and count the number of 
// elements which are less than equal to nums[i] + N - 1
// We need to perform operation on rest of the elements.

class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        int N = nums.size();
        int j = 0, ans = N;
        
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            while(j < nums.size() and nums[j] < nums[i] + N)
                j++;
            
            ans = min(ans, N - (j - i));
        }
        
        return ans;
    }
};
