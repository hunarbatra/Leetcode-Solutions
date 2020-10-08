class Solution {
public:
    vector<int> rotate(vector<int>& nums, int k) {
        if(k<1 || nums.size()<1) {return nums;} 
        if(k>nums.size()) {k%=nums.size();}        
        for(int i=0; i<k; i++) {
            nums.emplace(nums.begin(), nums.back()); nums.pop_back();
        }
        return nums;
    } 
};