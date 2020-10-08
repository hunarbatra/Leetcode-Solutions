class Solution {
public:
    bool backspaceCompare(string S, string T) {
        string str1, str2;
        int count1 = 0, count2 = 0;
        for(int i=S.size()-1; i>=0;) {
            if(S[i] == '#') {
                count1++;
                while(--i>=0 && S[i]=='#') {
                    count1++;
                }
                if(i<=0) break;
            } else if(isalnum(S[i])) {
                if(count1) {
                    count1--; i--;
                    continue;
                } else str1 += S[i--];
            }
        }
        for(int i=T.size()-1; i>=0;) {
            if(T[i] == '#') {
                count2++;
                while(--i>=0 && T[i]=='#') {
                    count2++;
                }
                if(i<=0) break;
            } else if(isalnum(T[i])) {
                if(count2) {
                    count2--; i--;
                    continue;
                } else str2 += T[i--];
            }
        }
        return str1 == str2;
    }
};