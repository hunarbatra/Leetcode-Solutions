class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        //checking the borders for O's and if it has any connecting O's and we are making them as 1
        //to keep a note that we have visited them, later we'll convert these 1's back to O's
        
        //vertical borders
        for(int i=0; i<rows; i++)  {
            if(board[i][0]=='O') 
                dfs(board, i, 0);
            if(board[i][cols-1]=='O')
                dfs(board, i, cols-1);     
        }
        //horizontal borders
        for(int j=1; j<cols-1; j++) {
            if(board[0][j]=='O') 
                dfs(board, 0, j);
            if(board[rows-1][j]=='O')
                dfs(board, rows-1, j);
        }
        //traversing the matrix (except for the border)
        for(int i=1;i<rows-1;i++) {
            for(int j=1; j<cols-1; j++) {
                if(board[i][j]=='O') board[i][j]='X';
            }
        }
        //traversing the entire matrix & changing the border and its connected O's from 1 to 0
        for(int i=0;i<rows;i++) {
            for(int j=0; j<cols; j++) {
                if(board[i][j]=='1') board[i][j]='O';
            }
        }
    }
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        if(i<0||j<0||i>board.size()-1||j>board[0].size()-1||board[i][j]=='X'||board[i][j]=='1') return;
        if(board[i][j]=='O') {
            board[i][j]='1';
            dfs(board, i+1, j); //down
            dfs(board, i-1, j); //up
            dfs(board, i, j+1); //right
            dfs(board, i, j-1); //left
        }
    }
};