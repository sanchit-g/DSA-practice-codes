class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> temp;
        
        dfs(res, temp, k, 1, n);
        
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& comb, int level, int i, int n) {
        if(!level) {
            res.push_back(comb);
            return;
        }
        
        for(int index = i; index <= n; index++) {
            comb.push_back(index);
            dfs(res, comb, level - 1, index + 1, n);
            comb.pop_back();
        }
    }
};
