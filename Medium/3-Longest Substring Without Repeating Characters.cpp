class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char, int> check;
        int longest = 1;
        int low = 0, high = 0;
        while(high < s.length() && low < s.length()) {
            if(check[s[high]]==0) {
                check[s[high]]++;
                longest = max(longest, high-low+1);
                high++;
            }
            else {
                check[s[low]]--;
                low++;
            }
        }
        return longest;
    }
};