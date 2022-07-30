class Solution {
public:
    
    void DFS(int i, int j, vector<vector<int>>& grid, int n, int m) {
        
        if(i < 0 or i >= n or j < 0 or j >= m or grid[i][j] != 0)
            return;
        
        grid[i][j] = -1;
        
        DFS(i + 1, j, grid, n, m);
        DFS(i - 1, j, grid, n, m);
        DFS(i, j + 1, grid, n, m);
        DFS(i, j - 1, grid, n, m);
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        // marking all the islands connected to boundary as visited
        // this is because we do not want to include these islands in our calculation
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    if(grid[i][j] == 0)
                        DFS(i, j, grid, n, m);
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    DFS(i, j, grid, n, m);
                    count++;
                }
            }
        }
        
        return count;
    }
};
