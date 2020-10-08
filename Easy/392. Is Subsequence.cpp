class Solution {
public:
    bool isSubsequence1(string s, string t) { // O(n)
        if(s.size()==0) return true;
        int s_pointer = 0, t_pointer = 0;
        while(t_pointer < t.length()) {
            if(t[t_pointer] == s[s_pointer]) {
                if(s_pointer == s.length()-1) return true;
                s_pointer++;
            }
            t_pointer++;
        }
        return false;
    }
    bool isSubsequence(string s, string t) { // O(lg n)
        if(s.size() > t.size()) return false;
        if(t.size()==0 && s.size()==0) return true;
        if(s.size()==0) return true;
        unordered_map<char, vector<int>> hashmap;
        for(int i=0; i<t.size(); i++) hashmap[t[i]].push_back(i); //char -> <indexes>
        int prev = -1;
        for(auto c : s) {
            auto it = hashmap.find(c);
            if(it == hashmap.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); //subtract to make int
            if(pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    } // Eg-1. s="abc", t="bahbgdca" // idx=[a={1,7}, b={0,3}, c={6}]
};    //  i=0 ('a'): prev=1
    //  i=1 ('b'): prev=3
    //  i=2 ('c'): prev=6 (return true)
    // Eg-2. s="abc", t="bahgdcb" // idx=[a={1}, b={0,6}, c={5}]
    //  i=0 ('a'): prev=1
    //  i=1 ('b'): prev=6
    //  i=2 ('c'): prev=? (return false)