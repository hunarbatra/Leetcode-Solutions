class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string s = countAndSay(n-1);
        string result="";
        for(int i=0;i<s.size();i++) {
            int count=1;
            while(s[i]==s[i+1] && i<s.size()) i++, count++;
            result.append(to_string(count)+s[i]);
        }
        return result;       
    }
};