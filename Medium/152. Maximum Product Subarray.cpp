class Solution {
public:
    int maxProduct(vector<int>& nums) {          
       //O(n)
        int currentMax = nums[0];
        int currentMin = nums[0];
        int max_product = nums[0];
        for(int i=1; i<nums.size(); i++) {
            int p1 = currentMax * nums[i];
            int p2 = currentMin * nums[i];
            currentMax = max(max(p1,p2), nums[i]);
            currentMin = min(min(p1,p2), nums[i]);
            max_product = max(currentMax, max_product);
        }
        return max_product;
    }
};