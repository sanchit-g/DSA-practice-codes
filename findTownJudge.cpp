class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        // using indegree and outdegree vectors
        
        if(trust.empty() and n == 1)
            return 1;
        
        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);
        
        for(auto& edge : trust) {
            outdegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        
        // if a node has outdegree = 0 that means that node does not trust anyone and
		// indegree = n-1 that means all other nodes trusts this node except himself
        
        for(int i = 0; i <= n; i++) {
            if(indegree[i] == n - 1 and outdegree[i] == 0)
                return i;
        }
        
        return -1;
    }
};
