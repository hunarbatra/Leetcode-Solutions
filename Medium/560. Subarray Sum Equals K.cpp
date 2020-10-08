class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int count = 0, sum = 0;
        unordered_map<int, int> visited;
        for(int i=0; i<nums.size(); i++) {
            visited[sum]++;
            sum += nums[i];
            if(visited[sum - target]) 
                count += visited[sum - target];
        }
        return count;
    }
};