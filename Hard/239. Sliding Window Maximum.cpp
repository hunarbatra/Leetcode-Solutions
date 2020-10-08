class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) { //O(n) DP & Space O(n)
        int n = nums.size();
        if(k == 1) return nums; if(n * k == 0) return {0};
        vector<int> left(n), right(n), result(n-k+1);
        left[0] = nums[0]; right[n-1] = nums[n-1];
        for(int i=1; i<n; i++) { //left to right
            if(i % k == 0) left[i] = nums[i]; //block start
            else left[i] = max(nums[i], left[i-1]);
            int j = n - 1 - i; //right to left
            if((j+1) % k == 0) right[j] = nums[j]; //block end
            else right[j] = max(nums[j], right[j+1]);
        }
        for(int i=0; i<n-k+1; i++) result[i] = max(left[i+k-1], right[i]);
        return result;
    }
    
    vector<int> maxSlidingWindow2(vector<int>& nums, int k) { //O(N log N)
        multiset<int> window;
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            window.insert(nums[i]);
            if(i >= k-1) {
                result.push_back(*window.rbegin());
                window.erase(window.find(nums[i-k+1])); //remove the first index from window
            }
        }
        return result;
    }
    vector<int> maxSlidingWindow1(vector<int>& nums, int k) { //Brute Force O(nk) & Space : O(n+k-1)
        int n = nums.size(), windows = n-k+1;
        if(n * k == 0) return {0};
        vector<int> result(windows);
        for(int i=0; i<windows; i++) {
            int curr_max = INT_MIN;
            for(int j=i; j<i+k; j++) {
                curr_max = max(curr_max, nums[j]);
            }
            result[i] = curr_max;
        }
        return result;
    }
};