class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size()) return "0";
        int n = num.size(), remain = n-k;
        string result = "";
        for(auto x : num) {
            while(n>remain && !result.empty() && result.back()-'0'>x-'0') {
                result.pop_back();
                n--;
            }
            result.push_back(x);
        }
        //remove trailing zeroes if any..
        int i=0;
        while(result[i]=='0' && i<result.size()) i++;
        return result.substr(i, remain) == "" ? "0" : result.substr(i, remain);
    }
};