class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> nums;
        nums['I'] = 1;
        nums['V'] = 5;
        nums['X'] = 10;
        nums['L'] = 50;
        nums['C'] = 100;
        nums['D'] = 500;
        nums['M'] = 1000;
        
        int sum = 0;
        for(int i=0;i<s.length();i++){
            //if eg : XIII i.e if left size letter is great than right side
            if(nums[s[i]] >= nums[s[i + 1]]) {
                sum += nums[s[i]];
            }
            else { //else if left size is smaller than right side, e.g : IX, the subtract
                sum += nums[s[i+1]] - nums[s[i]];
                i++; //Next letter has already been added, so advance to the next one
            }
        }
        return sum;
    }
};