class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0) return 0;
        if(s[0]=='0') return 0;
        vector<int> dp(s.length()+1);
        dp[0] = 1; //cause there's literally no way to decode a string of length 0
        dp[1] = 1;
        for(int i=2; i<=s.length(); i++) {
            int single_digit = stoi(s.substr(i-1, 1));
            int double_digit = stoi(s.substr(i-2, 2));
            if(single_digit>=1) 
                dp[i] += dp[i-1];
            if(double_digit >= 10 && double_digit <= 26) 
                dp[i] += dp[i-2];
        }
        return dp[s.length()];
    }
};