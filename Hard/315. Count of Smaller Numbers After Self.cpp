class Solution {
public:
     vector<int> countSmaller(vector<int>& nums) {
         if(nums.empty()) return {};
         vector<int> result(nums.size(),0), sortednums;
         for(int i=nums.size()-1; i>=0; i--) {
             int index = binarySearch(sortednums, nums[i]);
             result[i] = index; //index is the count
             sortednums.insert(sortednums.begin()+index, nums[i]);
         }
         return result;
    }
    
    // find the first position greater than or equal to target in sortedNums
    int binarySearch(vector<int>& sortedNums, int target){
        int l = 0, r = sortedNums.size();
        while(l < r){
            int m = l + (r - l) / 2; 
            if(sortedNums[m] < target) l = m + 1;
            else r = m;
        }
        
        return l;
    }
};