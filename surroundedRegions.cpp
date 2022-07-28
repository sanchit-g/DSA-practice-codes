class Solution {
public:
    void DFS(int i, int j, vector<vector<char>>& board, int rows, int cols) {
        
        // base case
        if(i < 0 or j < 0 or i >= rows or j >= cols or board[i][j] != 'O')
            return;
        
        board[i][j] = '#';
        
        // moving in four possible directions
        DFS(i-1, j, board, rows, cols);
        DFS(i+1, j, board, rows, cols);
        DFS(i, j-1, board, rows, cols);
        DFS(i, j+1, board, rows, cols);
    }
    
    void solve(vector<vector<char>>& board) {
        
         int m = board.size();
         int n = board[0].size();

         // Moving over first column 
         for(int i = 0; i < m; i++)
         {
             if(board[i][0] == 'O')
                 DFS(i, 0, board, m, n);
         }
         
         // Moving over last column
         for(int i = 0; i < m; i++)
         {
             if(board[i][n-1] == 'O')
                 DFS(i, n-1, board, m, n);
         }

         // Moving over first row   
         for(int j = 0; j < n; j++)
         {
             if(board[0][j] == 'O')
                 DFS(0, j, board, m, n);
         }
        
         // Moving over last row    
         for(int j = 0; j < n; j++)
         {
             if(board[m-1][j] == 'O')
                 DFS(m-1, j, board, m, n);
         }

         for(int i = 0; i < m; i++) {
             for(int j = 0; j < n; j++)
             {
                 if(board[i][j] == 'O')
                     board[i][j] = 'X';
                 
                 if(board[i][j] == '#')
                     board[i][j] = 'O';
             }
         }
    }
};
