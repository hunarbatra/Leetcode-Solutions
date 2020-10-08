class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i, j=0, n = s.length();
        vector<int> kmp(n, 0);
        for(i=1; i<n;){
            if(s[j] == s[i]) {
                kmp[i] = j+1;
                j++; //move j forward
                i++; //moves i forward and checks again
            }
             while(s[j] != s[i]) {
                if(j == 0) {
                    i++; //kmp[i] is already set as 0
                    break;
                }
                j = kmp[j-1]; //moves to the index in kmp[j-1]
            }
        }
        if(kmp[n-1]==0) return false; //i.e no repetition
        //checking if pattern is equally present in the enitre string
        if(kmp[n-1] % (n - kmp[n-1]) == 0) return true; 
        return false;
    }
};