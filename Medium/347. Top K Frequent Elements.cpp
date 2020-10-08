class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size()==0) return nums; //edge case
        unordered_map<int,int> umap;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) { //storing within the hash map
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it : umap) {
            pq.push({it.second, it.first});
        }
        while(k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};