class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        if(board.empty()) return false; //edge case
        if(word.length()==0) return false; //edge case
        if(rows*cols<word.length()) return false; //edge case
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                if(board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int counter, string& word) {
        if(counter==word.length()) return true; //signifies that we've reached the end of search
        if(i<0 || j<0 || i>board.size()-1 || j>board[0].size()-1 || board[i][j]!=word[counter]) 
            return false; //edge cases
        //storing * in board[i][j] to avoid revisiting it
        char temp = board[i][j];
        board[i][j] = ' ';
        bool result = dfs(board, i+1, j, counter+1, word) || dfs(board, i-1, j, counter+1, word) ||
                      dfs(board, i, j+1, counter+1, word) || dfs(board, i, j-1, counter+1, word);
        board[i][j] = temp;
        return result;
     }
};