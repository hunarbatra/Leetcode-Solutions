class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> numbersStore;
        vector<int> result(0);
        for(int number=0;number<nums1.size();number++) {
            numbersStore[nums1[number]]++;
        }
        for(int number=0;number<nums2.size();number++) {
            numbersStore[nums2[number]]--;
            if(numbersStore[nums2[number]] >= 0) {
                int intnum = nums2[number];
                result.push_back(intnum);
            }
            //if its -ve then we don't store it as its not an intersection then
        }
        return result;
    }
};