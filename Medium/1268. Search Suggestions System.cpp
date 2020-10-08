class Solution {
public:
    vector<vector<string>> suggestedProducts1(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        sort(products.begin(), products.end());\
        for(int i=0; i<searchWord.size(); i++) {
            vector<string> current;
            for(string s : products) {
                if(s.substr(0, i+1) == searchWord.substr(0, i+1)) {
                    current.push_back(s);
                    if(current.size() == 3) break;
                }
            }
            result.push_back(current);
        }
        return result;
    }
    //Optimized O(N log N) using Binary Search
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> result;
        string curr = "";
        sort(products.begin(), products.end());\
        for(int i=0; i<searchWord.size(); i++) {
            vector<string> current;
            curr += searchWord[i];
            auto it = lower_bound(products.begin(), products.end(), curr);
            for(; it!=products.end() && it->substr(0,i+1)==curr && current.size()<3; ++it) {
                current.push_back(*it);
            }
            result.push_back(current);
        }
        return result;
    }
};