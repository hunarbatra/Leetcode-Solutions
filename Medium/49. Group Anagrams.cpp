class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if(strs.empty()) return {};
        unordered_map<string, vector<string>> map;
        vector<vector<string>> result;
        for(auto s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s); 
        }
        
        for(auto x : map) {
            result.push_back(x.second);
        }
        return result;
    }
};