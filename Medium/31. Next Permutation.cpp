class Solution {
public:
    void nextPermutation(vector<int>& nums) { //O(n^2 log(n))
        if(nums.empty()) return;
        int start, end, n = nums.size();
        for(start=n-2; start>=0; start--) {
            if(nums[start]<nums[start+1])
                break;
        }
        if(start < 0) {
            reverse(nums.begin(), nums.end());
        } else {
            for(end=n-1; end>start; end--) {
                if(nums[end]>nums[start]) {
                   break;
                }
            }
            swap(nums, start, end);
            reverse(nums.begin()+start+1, nums.end());
        }
        return;
    }
    void swap(vector<int>& nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
