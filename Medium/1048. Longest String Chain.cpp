class Solution {
public:
    int longestStrChain(vector<string>& words) {
        if(words.empty()) return 0;
        sort(words.begin(), words.end(), [](string a, string b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int result = 0;
        for(string s : words) {
            for(int i=0; i<s.size(); i++) {
                string curr_str = s.substr(0,i) + s.substr(i+1); //skip ith char each tinme
                dp[s] = max(dp[s], dp[curr_str] + 1);
            }
            result = max(result, dp[s]);
        }
        return result;
    }
};