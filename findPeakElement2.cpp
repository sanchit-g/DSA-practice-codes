class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        int i = 0, j = col-1;
        
        while(i >= 0 && i < row && j >= 0 && j < col) {
            
            // finding nums in all 4 directions
            int up = i-1 < 0 ? -1 : mat[i-1][j];
            int down = i+1 >= row ? -1 : mat[i+1][j];
            int left = j-1 < 0 ? -1 : mat[i][j-1];
            int right = j+1 >= col ? -1 : mat[i][j+1];
            
            // check if current is peak
            if(mat[i][j] > up && mat[i][j] > left && mat[i][j] > right && mat[i][j] > down)
                return {i, j};
            
            // get maximum among 4 direction
            int maxi = max({up, down, left, right});
            
            // move in max direction
            if(up == maxi) i--;
            else if(down == maxi) i++;
            else if(left == maxi) j--;
            else if(right == maxi) j++;
        }
        
        return {-1, -1};
    }
};
