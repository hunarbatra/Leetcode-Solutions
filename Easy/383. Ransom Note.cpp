class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ransom;
        for(char c : ransomNote) ransom[c]++;
        for(char c : magazine) if(ransom[c]) ransom[c]--;
        for(char c : ransomNote) if(ransom[c]>0) return false;
        return true;
    }
};
