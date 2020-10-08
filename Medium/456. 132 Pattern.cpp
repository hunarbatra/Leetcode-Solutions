class Solution {
public:
    bool find132pattern(vector<int>& nums) { //O(n) Time & Space -> Stack
        if(nums.size() < 3) return false;
        stack<int> s3;
        int s2 = INT_MIN;
        for(int i=nums.size()-1; i>=0; i--) {
            if(nums[i] < s2) return true;
            else while(!s3.empty() && nums[i]>s3.top()) {
                s2 = s3.top(), s3.pop(); 
            }
            s3.push(nums[i]);
        }
        return false;
    }
/* Idea : Move from right to left. For every upward moving slope from the end, s2 will be the 2nd last element of that upward slope and s3 will ofcourse be the top most element of that slope. Thus, S2 gets updates from INT_MIN to its new value, we know that 3>2 comination exists. Now we need to check if there exists a combination of 1<2. Since 2 is no more INT_MIN, we can easily check for 1<2 by checking if nums[i]<s2. Also, s3 is a stack to find the highest peak and make s2 as peak-1 a.k.a next num after peak. */
    
    bool find132pattern2(vector<int>& nums) { //Better Brute Force O(N^2) -> TLE
        //Idea : find i<j and then k falls in i....j
        int min_i = INT_MAX;
        for(int j=0; j<nums.size(); j++) {
            min_i = min(min_i, nums[j]);
            for(int k=j+1; k<nums.size(); k++) {
                if(nums[k] < nums[j] && min_i < nums[k]) return true;
            }
        }
        return false;
    }
    
    bool find132pattern1(vector<int>& nums) { //Brute Force O(n^3) -> TLE
        int n = nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(nums[k]>nums[i] && nums[j]>nums[k]) return true;
                }
            }
        }
        return false;
    }
};