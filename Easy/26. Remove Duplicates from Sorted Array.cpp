class Solution {
public:
    //one liner
    int removeDuplicates(vector<int>& nums) {
       nums.erase(unique(nums.begin(),nums.end()),nums.end());
    }
    
    //other solution
    int removeDuplicates(vector<int>& nums) {
       for(int i=1; i<nums.size();) {
           if(nums[i] == nums[i-1])
           {
               //if the 2nd number is equal to 1st
               auto it=nums.begin()+i; //increment it to position of 2nd number
               nums.erase(it); //remove the 2nd number
           }
           else
           {   //if 2nd number is not a duplicate of 1st
               i++; //increment i to check for the next numbers
           } 
       } 
        return nums.size();
    }
};