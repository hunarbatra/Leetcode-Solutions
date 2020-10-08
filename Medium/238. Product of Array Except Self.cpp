class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        //O(n) with constant space
       // if(nums.size()==2) {swap(nums[0],nums[1]); return nums;}                                          
        //if(nums.size()<=1) return nums;
        vector<int> outputarr(nums.size());
        outputarr[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            outputarr[i]=outputarr[i-1]*nums[i-1];
        }
        int rcounter=1;
        for(int i=nums.size()-1;i>=0;i--)
        {
            outputarr[i]*=rcounter;
            rcounter*=nums[i];
        }
        return outputarr;
        
       //O(n) w/o constant space
        vector<int> leftproduct(nums.size());
        vector<int> rightproduct(nums.size());
        vector<int> outputarr(nums.size());
        
        leftproduct[0]=1;
        rightproduct[nums.size()-1]=1;
        
        for(int i=1;i<nums.size();i++)
        {
            leftproduct[i]=leftproduct[i-1]*nums[i-1];
        }
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            rightproduct[i]=rightproduct[i+1]*nums[i+1];
        }
        
        for(int i=0;i<nums.size();i++)
        {
            outputarr[i]=leftproduct[i]*rightproduct[i];
        }
        
        return outputarr;
       
        
       //O(n^2) solution
        if(nums.size()<=1) return nums;
        int product=1;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums.size();j++)
            {
                if(i==j) continue;
                else product*=nums[j];
            }
            res.push_back(product);
            product=1;
        }
        return res;
    }
};