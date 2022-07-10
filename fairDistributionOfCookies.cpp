// this solution is only accepted due to low constraints
// more efficient solutions also exist

class Solution {
public:
    
    int ans = INT_MAX;
    
    void solve(int start, vector<int>& cookies, vector<int>& v) {
        
        // base case
        if(start == cookies.size())
        {
            ans = min(ans, *max_element(v.begin(), v.end()));
            return;
        }
        
        // first give all the cookies to the same child
        // then remove the last given cookie and give it to the next child and so on...
        for(auto &it : v)
        {
            // if v[i] += cookies[start] increases v[i] more than the current ans, no need to continue with this 
            if(it + cookies[start] > ans)
                continue;
            
            it += cookies[start];
            solve(start + 1, cookies, v);
            it -= cookies[start];
        }
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        
        // vector v refers to the count of cookies each child got
        vector<int> v(k, 0);
        solve(0, cookies, v);
        
        return ans;
    }
};
