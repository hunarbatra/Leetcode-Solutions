class Solution {
private:
    vector<int> v;
public:
    Solution(vector<int>& w) {
        for(int ind : w) {
            if(v.empty()) v.push_back(ind);
            else v.push_back(ind + v.back());
        }
    }
    
    int pickIndex() {
        int index = rand() % v.back(); //generate a random number
        auto it = upper_bound(v.begin(), v.end(), index);
        return it - v.begin(); 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */