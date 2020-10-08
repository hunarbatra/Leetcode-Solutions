class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int left = 0, right = nums.size()-1;
        while(left < right) {
            int mid = left+(right-left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else if(nums[mid] < nums[right]) right = mid; 
            else right--;
        }
        return nums[left];
    }
    
    int findMinTwo(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int left = 0, right = nums.size()-1;
        while(right > 0 && nums[right] == nums[left]) right--; 
        while(left < right) {
            int mid = left+(right-left) / 2;
            if(nums[mid] > nums[right]) left = mid + 1;
            else right = mid; 
        }
        return nums[left];
    }
};