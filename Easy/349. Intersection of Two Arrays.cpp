class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty()) return {};
        if(nums1.empty() || nums2.empty()) return {};
        unordered_map<int,int> hashmap;
        vector<int> result;
        //first traverse the first num
        for(int i : nums1) hashmap[i]=1; 
        //traverse second num and check for intersection
        for(int i : nums2) {
            hashmap[i]--;
            if(hashmap[i]==0) { //intersection
                result.push_back(i);
            }
        } 
        return result;
    }
};