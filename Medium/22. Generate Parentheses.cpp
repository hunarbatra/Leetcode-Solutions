class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, n, "", result);
        return result;
    }
    
    void generate(int left, int right, string path, vector<string>& result) {
        if(left == 0 && right == 0) { //if number of left/right paren == 0, append curr str
            result.push_back(path); 
            return;
        }
        if(left > 0) { //we can insert left paren only when total count is > 0
            generate(left-1, right, path+"(", result);
        }
        if(left < right) { //we can insert right paren only when we have opened a left_p
            generate(left, right-1, path+")", result);
        }
    }
};