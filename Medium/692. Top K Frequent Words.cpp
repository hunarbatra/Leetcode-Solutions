class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> umap;
        for(string w : words) {
            umap[w]++;
        }
        vector<pair<string,int>> vec(umap.begin(), umap.end());
        stable_sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            return a.second == b.second ? a.first < b.first : a.second>b.second;
        });
        vector<string> result;
        for(int i=0; i<k; ++i) {
            result.push_back(vec[i].first);
        }
        return result;
    }
};