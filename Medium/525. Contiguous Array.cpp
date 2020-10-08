class Solution {
public:
    int findMaxLength(vector<int>& nums) { //O(N) time and space
       int sum = 0;
       unordered_map<int,int> umap;
       int longestContArray = 0;
        for(int i=0; i<nums.size(); i++) {
           sum += (nums[i]==0) ? -1 : 1;
           auto it = umap.find(sum);
           if(sum == 0) longestContArray = max(longestContArray, i+1); //starting from 0th index longest consec arr
           else if(it != umap.end()) longestContArray = max(longestContArray, i - it->second);
           else umap.insert({sum,i});
       }
        return longestContArray;
    }
    
    int findMaxLength1(vector<int>& nums) { //Brute Force O(n^2)
        if(nums.empty()) return 0;
        int zero_count = 0, one_count = 0, max_len = INT_MIN;
        for(int i=0; i<nums.size()-1; i++) {
            for(int j=i; j<nums.size(); j++) {
                if(nums[j] == 0) zero_count++;
                else one_count++;
                if(zero_count == one_count) max_len = max(max_len, j-i+1);
            }
        }
        return max_len;
    }
};