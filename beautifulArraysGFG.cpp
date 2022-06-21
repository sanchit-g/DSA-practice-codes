class Solution {
  public:
    int beautifulArray(vector<int>& a, int x, int k) {
        
        int n = a.size();
        
        sort(a.begin(), a.end());
        
        vector<int> gaps;
        for(int i = 1; i < n; i++)
        {
            if(a[i] - a[i-1] > k)
                gaps.push_back(a[i] - a[i-1]);
        }
        
        sort(gaps.begin(), gaps.end());
        
        int count = gaps.size() + 1;
        for(int i = 0; i < gaps.size() and x > 0; i++)
        {
            int additional = gaps[i] / k;
            if(gaps[i] % k == 0)
                additional--;
            if(x - additional >= 0) {
                x -= additional;
                count--;
            }
        }
        
        return count;
    }
};
