class Solution {
public:
    int search(vector<int>& nums, int target) {
        //brute force ->
        //O(n) check every element if its equal to the given i.e linear search
        
        //O(lg N) binary search
        
        //lets check edge cases first
        if(nums.empty()) return -1;
        
        int left=0, right=nums.size()-1; //two pointers, l points to beginning and r to end of vector
        //first we do a modified binary search to find the actual start of sorted array
        while(left < right)
        {
            int mid = (left+right) / 2;
            if(nums[mid]>nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        
        int start = left; //left points to smallest element in array rn
        left = 0; right = nums.size()-1; //initializing left and right for another search
        
        if(target>=nums[start] && target<=nums[right])
            left = start; //if target lies in 2nd part of array we set our left pointer there
        else
            right = start; //if not, then target lies in first half and we set our right pointer
       
        //now we will perform a regular binary search
             //left <= right cause this is the actual binary search condition
            //for the modified we used l < r, because we wanted only left to point to start
            //and if we do not add l<r then it results in an infite loop as it keeps on becoming =
        while(left <= right)
        {
            int mid = (left+right) / 2;
            if(nums[mid] == target)
                return mid;
            else if(target > nums[mid])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1; //if target number is not found, then -1 is returned
        //if target is found then regular binary search will return the mid index for that
    }
};