class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        
        int n = rains.size();
        
        unordered_map<int, int> fulllakes;
        set<int> drydays;
        vector<int> ans(n, 1);
        
        for(int i = 0; i < n; i++)
        {
            if(rains[i] == 0) drydays.insert(i);
            
            else
            {
                int lake = rains[i];
                
                if(fulllakes.find(lake) != fulllakes.end())
                {
                    auto it = drydays.upper_bound(fulllakes[lake]);
                    
                    if(it == drydays.end()) return {};
                    
                    int dryday = *it;
                    ans[dryday] = lake;
                    drydays.erase(dryday);
                }
                
                fulllakes[lake] = i;
                ans[i] = -1;
            }
        }
        
        return ans;
    }
};
