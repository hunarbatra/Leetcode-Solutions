class Solution {
public:
    int balancedStringSplit(string s) {
        int r_count = 0, split_count = 0;
        for(int i=0; i<s.size();) {
            while(s[i]=='R') {
                r_count++;
                if(r_count == 0) {
                    split_count++;
                }
                i++;
            }
            while(s[i]=='L') {
                r_count--;
                if(r_count == 0) {
                    split_count++;
                }
                i++;
            }
            
        }
        return split_count;
    }
};