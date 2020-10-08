class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;
        if(target > nums.back()) return nums.size();
        if(target < nums.front()) return 0;
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = left+(right-left)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] < target) left = mid + 1;
            if(nums[mid] > target) right = mid;
        }
        return left;
    }
};