class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) return true;
        if(wordDict.empty()) return false;
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i=1; i<dp.size(); i++) {
           for(string &w : wordDict)
			if(i >= w.size() && dp[i - w.size()] && s.substr(i - w.size(), w.size()) == w) {
				dp[i] = true;
			}
        }
        return dp[s.size()];
    }
};