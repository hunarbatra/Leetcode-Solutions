class Solution {
public:
    int maxSubArray(vector<int>& nums) {  
        int max_sum=INT_MIN, sum=0;
        for (auto i : nums) {
            sum=max(sum+i, i);
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};