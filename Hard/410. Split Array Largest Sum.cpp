class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        if(nums.empty() || m==0) return 0;
        size_t left = 0, right = 0;
        for(size_t n : nums) {
            left = max(left, n); //highest number i.e the max it'll go incase of m==nums.size()
            right += n; //total sum i.e the max it can go incase of m==1
        }
        if(m == nums.size()) return left; //edge case
        if(m == 1) return right; //edge case
        while(left < right) {//modified binary search w/ search space b/w highestnum...totalsum
            size_t mid = (left + right) / 2;
            size_t curr_bagsize = 0, curr_m = 1;
            for(auto n : nums) {
                if(curr_bagsize + n > mid) { //bag m is full, try the next bag now
                    curr_m++; 
                    curr_bagsize = 0;
                }
                curr_bagsize += n;
            } 
            if(curr_m > m) //we need a bigger bag size if curr_m > m
                left = mid + 1;
            else //current bag size is sufficient enough, so check for smaller bag sizes
                right = mid;
        }
        return left;
    }
};

/*
Complexity :
Time - O(n log m), where m = binary search search space -> totalSum - highestNum
& n = number of non-negative integers in array nums
Space - O(1) -> Inplace
*/