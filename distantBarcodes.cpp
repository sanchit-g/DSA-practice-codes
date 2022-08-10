class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        
        unordered_map<int, int> mp;
        
        for(int& i : barcodes)
            mp[i]++;
        
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        
        for(auto& p : mp) {
            pq.push({p.second, p.first});
        }
        
        while(!pq.empty()) {
            auto [freq1, num1] = pq.top();
            pq.pop();
            
            ans.push_back(num1);
            
            if(pq.size() >= 1) {
                auto [freq2, num2] = pq.top();
                pq.pop();
                
                ans.push_back(num2);
                
                if((freq2 - 1) > 0)
                    pq.push({freq2 - 1, num2});
            }
            
            if((freq1 - 1) > 0)
                    pq.push({freq1 - 1, num1});
        }
        
        return ans;
    }
};
