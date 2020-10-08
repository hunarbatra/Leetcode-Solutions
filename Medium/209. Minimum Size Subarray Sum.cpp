class Solution {
public:
    int minSubArrayLenOne(int s, vector<int>& nums) { //O(n)
        if(nums.empty()) return 0;
        int low = 0, high = 0, min_length = INT_MAX, sum = 0;
        while(high<=nums.size()-1) {
            sum += nums[high];
            while(sum >= s) {
                min_length = min(min_length, high-low+1);
                sum -= nums[low];
                low++;
            }
            high++;
        }
        return min_length == INT_MAX ? 0 : min_length;
    } //Since each element in nums will be visited by l and r for at most once. This algorithm is of O(n) time.
    
    int minSubArrayLen(int s, vector<int>& nums) { //O(nlogn) for multiple arrays
        int len = INT_MAX, n = nums.size();
        vector<int> sum(n+1, 0);
        for(int i=1; i<sum.size(); i++) {
           sum[i] = sum[i-1] + nums[i-1]; 
        }
        for(int i=n; i>=0 && sum[i]>=s; i--) {
            int j = upper_bound(sum.begin(), sum.end(), sum[i]-s) - sum.begin();
            len = min(len, i-j+1);
        }
        return len == INT_MAX ? 0 : len;
    }
};