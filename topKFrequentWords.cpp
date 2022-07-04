// O(N*log(K)) solution

#define psi pair<int, string>

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        int n = words.size();
        unordered_map<string, int> freq;
        
        for(string s : words) {
            freq[s]++;
        }
        
        auto comp = [](const psi &a, const psi &b) {
            
            if(a.first == b.first)
                return a.second < b.second;
            
            return a.first > b.first;
        };
        
        priority_queue<psi, vector<psi>, decltype(comp)> pq(comp);
        
        for(auto it : freq) {
            pq.push({it.second, it.first});
            
            if(pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> ans(k);
        int i = k - 1;
        
        while(pq.size()) {
            ans[i--] = pq.top().second;
            pq.pop();
        }
        
        return ans;
    }
};
