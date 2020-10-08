class Solution {
public:
    vector<int> smallerNumbersThanCurrentOn2(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> result;
        for(int i=0; i<nums.size(); i++) {
            vector<int> temp;
            for(int j=0; j<nums.size(); j++) {
                if(nums[j] < nums[i]) {
                    temp.push_back(nums[j]);
                }
            }
            result.push_back(temp.size());
        }
        return result;
     }
    
    vector<int> smallerNumbersThanCurrentBS(vector<int>& nums) {
        if(nums.empty()) return {};
        vector<int> temp = move(nums);
        vector<int> result;
        sort(temp.begin(), temp.end());
        for(int i=0; i<nums.size(); i++) {
            int left = 0, right = temp.size()-1;
            while(left < right) {
                int mid = left+right/2;
                if(temp[mid] < nums[i]) left = mid + 1;
                else right = mid;
            }
            result.push_back(left);
        }
        return result;
     }
    //Running sums -kinda like counting sort - summing up etc.
     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
         if(nums.empty()) return {};
         vector<int> result(nums.size());
         vector<int> count(101, 0); //nums[i] value is b/w 0...100
         for(int i=0; i<nums.size(); i++) count[nums[i]]++; //count no. of occurences
         for(int i=1; i<=100; i++) {
             count[i] += count[i-1]; //current = current_count + prev_count -> summing up
         }
         for(int i=0; i<nums.size(); i++) {
             if(nums[i]==0) result[i] = 0;
             else result[i] = count[nums[i] - 1];
         }
         return result;
     }
};