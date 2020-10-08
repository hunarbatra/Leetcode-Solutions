class Solution {
public:
    int countSubstrings(string s) {
        if(s.length()==0) return 0;
        int res= 0;
        for(int i=0; i<s.length(); i++) {
            expandAroundCenter(s, i, i, res);
            expandAroundCenter(s, i, i+1, res);
        }
        return res;
    }
    
    int expandAroundCenter(string s, int left, int right, int& res) {
        if(s.length()==0 || left>right) return 0;
        while(left>=0 && right<s.length() && s[left]==s[right]) left--, right++, res++;
        return res;
    }
};