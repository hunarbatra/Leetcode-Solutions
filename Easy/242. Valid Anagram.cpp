class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int> lettersStore;
        if(s.length()!=t.length()) return false;
        for(int i=0; i<s.length(); i++) {
            lettersStore[s[i]]++;
        }
        for(int i=0; i<t.length(); i++) {
           lettersStore[t[i]]--;
           if(lettersStore[t[i]] < 0) {
               return false;
           }
        }
        return true;
    }
};