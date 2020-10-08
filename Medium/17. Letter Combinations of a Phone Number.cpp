class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> result;
        vector<string> letters({"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        dfs(0, "", digits, letters, result);
        return result;
    }
    
    void dfs(int cur_pos, string path, string digits, vector<string>& letters, vector<string>& result) {
        if(cur_pos == digits.size()) {
            result.push_back(path);
            return;
        }
        for(auto c : letters[digits[cur_pos]-'0']) {
            path.push_back(c);
            dfs(cur_pos+1, path, digits, letters, result);
            path.pop_back(); 
        }
    }
};