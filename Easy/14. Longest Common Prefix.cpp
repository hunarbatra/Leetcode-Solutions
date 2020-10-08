class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(), strs.end());
        string a = strs[0], b = strs.back();
        int i = 0;
        for(; i < min(a.size(), b.size()); i++) if(a[i] != b[i]) break;
        return a.substr(0, i);
    }
};