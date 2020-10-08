class Solution {
public:
    bool checkValidString(string s) { //Greedy O(n)
    int lo = 0, hi = 0;
       for (char c : s) {
           lo += c == '(' ? 1 : -1;
           hi += c != ')' ? 1 : -1;
           if (hi < 0) break;
           lo = max(lo, 0);
       }
       return lo == 0;
    }
};