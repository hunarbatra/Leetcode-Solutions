class Solution {
public:
   int getSum(int a, int b) {
        vector<int> nums({a,b});
        int sum = 0;
        return accumulate(nums.begin(), nums.end(), sum);
    } 
};