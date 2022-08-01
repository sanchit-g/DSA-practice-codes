class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        queue<pair<int, int>> q;
        vector<vector<int>> dist(row, vector<int>(col, -1));
        
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,1}, {0,-1}};
        
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();
            
            int x = p.first, y = p.second;
            
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = 1 + dist[x][y];
                    q.push({nx, ny});
                }
            }
        }
        
        return dist;
    }
};
