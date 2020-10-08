class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty()) return 0;
        if(needle.length()>haystack.length()) return -1;
        const char *h = haystack.c_str();
        const char *n = needle.c_str();
        const char *r = strstr(h,n);
        if(!r) return -1;
        return r-h;       
    }
};