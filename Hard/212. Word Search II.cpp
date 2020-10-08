class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size(), cols = board[0].size();
        vector<string> result;
        if(board.empty()) return {}; //edge case
        for(int i=0; i<rows; ++i) {
            for(int j=0; j<cols; ++j) {
                for(string w : words) {
                    if(board[i][j] == w[0] && dfs(board, i, j, 0, w) && 
                       find(result.begin(), result.end(), w) == result.end()) {
                        result.push_back(w);
                    }
                }
            }
        }
        return result;
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

//Trie Solution
struct TrieNode{
    string word;
    TrieNode* next[26] = {nullptr};
};
class Solution {
private:
    TrieNode* root;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        buildTrie(words);
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[0].size(); j++)
                backtrack(board, res, i, j, root);
        return res;
    }
    void backtrack(vector<vector<char>>& board, vector<string>& res, int r, int c, TrieNode* p){
        if(r<0||c<0||r>board.size()-1||c>board[0].size()-1||board[r][c]=='0'||!p->next[board[r][c]-'a']) 
            return;
        p = p->next[board[r][c] - 'a'];
        if(p->word.size() > 0) {
            res.push_back(p->word);
            p->word = "";
        } 
        char tmp = board[r][c];
        board[r][c] = '0';
        backtrack(board, res, r - 1, c, p); backtrack(board, res, r + 1, c, p);
        backtrack(board, res, r, c + 1, p);backtrack(board, res, r, c - 1, p);
        board[r][c] = tmp;
    }
    void buildTrie(vector<string>& words){
        root = new TrieNode();
        for(auto x: words) {
            TrieNode* current = root;
            for(auto c: x){
                if(!current->next[c - 'a']) 
                    current->next[c - 'a'] = new TrieNode();
                current = current->next[c - 'a'];
            }
            current->word = x;
        } 
    }
};