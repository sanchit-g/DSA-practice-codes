// using Disjoint Set Union

class Solution {
public:
    
    int parent[2001];
    int rank[2001];
    
    void make(int u) {
        parent[u] = u;
        rank[u] = 0;
    }
    
    int findParent(int u) {
        if(u == parent[u])
            return u;
        
        // with path compression
        return parent[u] = findParent(parent[u]);
    }
    
    void unionSet(int u, int v) {
        u = findParent(u);
        v = findParent(v);
        
        if(rank[u] < rank[v])
            parent[u] = v;
        
        else if(rank[v] < rank[u])
            parent[v] = u;
        
        else {
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        
        for(int i = 0; i < n; i++)
            make(i);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1)
                    unionSet(i, j);
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            if(findParent(i) == i)
                count++;
        }
        
        return count;
    }
};
