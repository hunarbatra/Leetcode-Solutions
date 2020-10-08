class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> freq;
        string curr;
        for(int i=0; i<paragraph.size(); ++i) {
            if(paragraph[i] == ' ' || paragraph[i] == ',' || i==paragraph.size()-1) {
                if(isalnum(paragraph[i])) curr += tolower(paragraph[i]);
                if(curr != "") freq[curr]++;
                curr = "";
            } else if(isalnum(paragraph[i])) curr += tolower(paragraph[i]);
        }
        vector<pair<int,string>> result;
        for(auto x : freq) {
            string curr = x.first; int count = x.second;
            if(find(banned.begin(), banned.end(), curr) == banned.end()) 
                result.push_back({count,curr});
        }
        stable_sort(result.begin(), result.end(), [](auto& a, auto&b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        });
        return result[0].second;
    }
};
//O(N log N)