class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        
        int N = days.size(), ans = 0, day = 0;
        
        // min heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        for(int i = 0; i < N; i++)
        {
            day++;
            pq.push({i+days[i], apples[i]});
            
            // remove the rotten apples
            while(!pq.empty() and pq.top().first < day)
                pq.pop();
            
            if(pq.empty())  continue;
            
            // now eat the one with the smallest end time and insert the remaining back in pq
            auto [a, b] = pq.top();
            pq.pop();
            ans++;
            
            if (b > 1)
                pq.push({a, b-1});
        }
        
        // now eat the remaining apples in the pq (obviously, if they are not expired)
        while(!pq.empty())
        {
            day++;
            
            while(!pq.empty() and pq.top().first < day)
                pq.pop();
            
            if(pq.empty())
                break;
            
            auto [a, b] = pq.top();
            pq.pop();
            ans++;
            
            if (b > 1)
                pq.push({a, b-1});
        }
        
        return ans;
    }
};
